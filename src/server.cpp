#include "server.h"
#include <random>



bool ChatServer::isTokenValid(const TokenLoginPair& token) const
{
    auto pos = std::find(_tokens.begin(), _tokens.end(), token);
    if (pos == _tokens.end())
        return false;
    return true;
}

std::string ChatServer::generateToken()
{
    auto pos = _tokens.begin();
    std::string generatedToken;
    do
    {
        generatedToken = random_string();
        for (const TokenLoginPair& element : _tokens)
        {
            if (element.token == generatedToken)
            {
                pos = _tokens.begin();
                break;
            }
            pos = _tokens.end();
        }
    } while (pos != _tokens.end());
    return generatedToken;
}

grpc::Status ChatServer::signUp(::grpc::ServerContext* context, const::net_service::CredentialsSignUp* request, ::net_service::Token* response)
{
    auto isUserPresent = [&request](const User& user)
    {
        return ((request->username() == user.username) || (request->login() == user.login));
    };

    response->set_result(false);
    if (std::any_of(_users.begin(), _users.end(), isUserPresent))
    {
        return grpc::Status::OK;
    }

    _users.push_back({ request->login(),request->username(),request->hash() });
    const std::string generatedToken = generateToken();

    _tokens.push_back({ generatedToken, request->login() });
    response->set_token(generatedToken);
    response->set_result(true);

    return grpc::Status::OK;
}

grpc::Status ChatServer::signIn(::grpc::ServerContext* context, const::net_service::CredentialsSignIn* request, ::net_service::Token* response)
{
    response->set_result(false);
    auto isLoginPresent = [&request](const User& user)
    {
        return request->login() == user.login;
    };
    auto login = std::find_if(_users.begin(), _users.end(), isLoginPresent);
    if (login == _users.end() || login->hash!=request->hash())
        return grpc::Status::OK;
    std::string generatedToken = generateToken();
    _tokens.push_back({ generatedToken, request->login() });
    response->set_token(generatedToken);
    response->set_result(true);

    return grpc::Status::OK;

}

grpc::Status ChatServer::signOff(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::Token* response)
{
    response->set_result(false);
    auto isTokenPresent = [&request](const TokenLoginPair& tokenPair)
    {
        return request->token() == tokenPair.token;
    };
    const auto token = std::find_if(_tokens.begin(), _tokens.end(), isTokenPresent);
    _tokens.erase(token);
    response->set_result(true);
    return grpc::Status::OK;
}

grpc::Status ChatServer::savePublicMessage(::grpc::ServerContext* context, const::net_service::PublicMessageSave* request, ::net_service::Token* response)
{
    response->set_result(false);
    auto isSenderPresent = [&request](const User& user)
    {
        return request->sender() == user.username;
    };
    const auto sender = std::find_if(_users.begin(), _users.end(), isSenderPresent);

    auto isTokenPresent = [&request](const TokenLoginPair& tokenPair)
    {
        return request->token() == tokenPair.token;
    };
    const auto token = std::find_if(_tokens.begin(), _tokens.end(), isTokenPresent);
    if(sender == _users.end() || token == _tokens.end())
        return grpc::Status::OK;

    _publicMessages.push_back({ request->content(), request->sender() });
    response->set_result(true);
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPublicMessages(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::PublicMessageLoad* response)
{
    //std::vector<PublicMessage> publicMessages
    return grpc::Status();
}

grpc::Status ChatServer::savePrivateMessage(::grpc::ServerContext* context, const::net_service::PrivateMessageSave* request, ::net_service::Token* response)
{
    auto isSenderPresent = [&request](const User& user)
    {
        return request->sender() == user.username;
    };
    auto isRecieverPresent = [&request](const User& user)
    {
        return request->reciever() == user.username;
    };
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPrivateMessages(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::PrivateMessageLoad* response)
{
    return grpc::Status();
}

std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size()-1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }
    return random_string;
}

bool TokenLoginPair::operator==(const TokenLoginPair& rhs) const
{
    return rhs.token==token && rhs.login==login;
}
