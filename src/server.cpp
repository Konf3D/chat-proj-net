#include "server.h"
#include <random>
#include <fstream>

constexpr auto dbUsersFileName = "users.db";
constexpr auto dbPublicMessagesFileName = "publicmessages.db";
constexpr auto dbPrivateMessagesFileName = "privatemessages.db";

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

ChatServer::ChatServer()
    :net_service::net_service::Service()
{
#ifdef WIN32
    /* check if database files are present*/
    system("ni users.db");
    system("ni publicmessages.db");
    system("ni privatemessages.db");
#elif unix
    system("touch users.db && chmod 600 users.db");
    system("touch publicmessages.db && chmod 600 publicmessages.db");
    system("touch privatemessages.db && chmod 600 privatemessages.db");
#endif
    /* LOADING DATA FROM LOCAL DATABASE*/
    /* LOADING USERS*/
    std::fstream m_usersDBFile(dbUsersFileName, std::ios::out | std::ios::in);
    std::string login;
    std::string password;
    std::string username;
    while (!m_usersDBFile.eof())
    {
        std::getline(m_usersDBFile, login);
        if (m_usersDBFile.eof())
            break;
        std::getline(m_usersDBFile, password);
        if (m_usersDBFile.eof())
            break;
        std::getline(m_usersDBFile, username);
        _users.push_back({ login, password, username });
    }
    /* LOADING PUBLIC MESSAGES*/
    std::fstream m_messageDBFile;
    m_messageDBFile.open(dbPublicMessagesFileName, std::ios::out | std::ios::in);
    std::string message;
    std::string sender;
    std::string reciever;
    while (!m_messageDBFile.eof())
    {
        std::getline(m_messageDBFile, message);
        if (m_messageDBFile.eof())
            break;
        std::getline(m_messageDBFile, sender);
        _publicMessages.push_back({ message,sender });
    }
    m_messageDBFile.close();
    /* LOADING PRIVATE MESSAGES*/
    m_messageDBFile.open(dbPrivateMessagesFileName, std::ios::out | std::ios::in);
    while (!m_messageDBFile.eof())
    {
        std::getline(m_messageDBFile, message);
        if (m_messageDBFile.eof())
            break;
        std::getline(m_messageDBFile, sender);
        if (m_messageDBFile.eof())
            break;
        std::getline(m_messageDBFile, reciever);
        _privateMessages.push_back({ message,sender,reciever });
    }
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
    std::vector<PublicMessage*> publicMessages;
    std::string login;
    
    for (const auto& element : _tokens)
    {
        if (element.token == request->token())
            login = element.login;

    }
    if (login.empty())
        return grpc::Status::OK;
    for (const auto& element : _publicMessages)
    {
        response->add_content(element.content);
        response->add_sender(element.sender);
    }
    return grpc::Status::OK;
}

grpc::Status ChatServer::savePrivateMessage(::grpc::ServerContext* context, const::net_service::PrivateMessageSave* request, ::net_service::Token* response)
{
    response->set_result(false);
    auto isSenderPresent = [&request](const User& user)
    {
        return request->sender() == user.username;
    };
    const auto sender = std::find_if(_users.begin(), _users.end(), isSenderPresent);

    auto isRecieverPresent = [&request](const User& user)
    {
        return request->reciever() == user.username;
    };
    const auto reciever = std::find_if(_users.begin(), _users.end(), isRecieverPresent);

    auto isTokenPresent = [&request](const TokenLoginPair& tokenPair)
    {
        return request->token() == tokenPair.token;
    };
    const auto token = std::find_if(_tokens.begin(), _tokens.end(), isTokenPresent);
    if (reciever == _users.end() || sender == _users.end() || token == _tokens.end())
        return grpc::Status::OK;

    _privateMessages.push_back({ request->content(),request->sender(),request->reciever() });
    response->set_result(true);
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPrivateMessages(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::PrivateMessageLoad* response)
{
    std::vector<PublicMessage*> publicMessages;
    std::string login;
    for (const auto& element : _tokens)
    {
        if (element.token == request->token())
            login = element.login;

    }
    if (login.empty())
        return grpc::Status::OK;

    std::string username;
    for (const auto& element : _users)
    {
        if (element.login == login)
            username = element.username;

    }
    if (username.empty())
        grpc::Status::CANCELLED;
    for (const auto& element : _privateMessages)
    {
        if (element.reciever == username || element.sender == username)
        {
            response->add_content(element.content);
            response->add_sender(element.sender);
            response->add_reciever(element.reciever);
        }
    }
    return grpc::Status::OK;
}

grpc::Status ChatServer::getUsername(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::Token* response)
{

    auto isUserPresent = [&request](const User& user)
    {
        return ((request->token() == user.username) || (request->token() == user.login));
    };
    response->set_token(std::find_if(_users.begin(), _users.end(), isUserPresent)->username);

    return grpc::Status::OK;
}

std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size()-1);

    std::string random_string;

    for (size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }
    return random_string;
}

bool TokenLoginPair::operator==(const TokenLoginPair& rhs) const
{
    return rhs.token==token && rhs.login==login;
}
