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
            ++pos;
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
    auto isTokenPresent = []()
    {

    };
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPublicMessagess(::grpc::ServerContext* context, const::net_service::MsgPos* request, ::net_service::PublicMessageLoad* response)
{
    return grpc::Status::OK;
}


grpc::Status ChatServer::getPrivateMessages(::grpc::ServerContext* context, const::net_service::MsgPos* request, ::net_service::PrivateMessageLoad* response)
{
    return grpc::Status::OK;
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
    return rhs.token==this->token && rhs.login==this->login;
}
