#pragma once
#include <iostream>
#include <vector>
#include <grpc++/grpc++.h>
#include <utility>
#include "../proto/net_service.grpc.pb.h"

struct PublicMessage
{
    std::string context;
    std::string sender;
};
struct PrivateMessage : public PublicMessage
{
    std::string reciever;
};
struct User
{
    std::string login;
    std::string username;
    std::string hash;
};
struct TokenLoginPair
{
    std::string token;
    std::string login;
    bool operator==(const TokenLoginPair& rhs) const;
};
std::string random_string(std::size_t length = 64);
class ChatServer : public net_service::net_service::Service
{
private:
    std::vector<User> _users;
    std::vector<PublicMessage> _publicMessages;
    std::vector<PrivateMessage> _privateMessages;
    //username+random unique token
    std::vector<TokenLoginPair> _tokens;
    bool isTokenValid(const TokenLoginPair& token) const;
    std::string generateToken();
public:
    grpc::Status signUp(::grpc::ServerContext* context, const ::net_service::CredentialsSignUp* request, ::net_service::Token* response);
    grpc::Status signIn(::grpc::ServerContext* context, const ::net_service::CredentialsSignIn* request, ::net_service::Token* response);
    grpc::Status signOff(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::Token* response);
    grpc::Status savePublicMessage(::grpc::ServerContext* context, const ::net_service::PublicMessageSave* request, ::net_service::Token* response);
    grpc::Status getPublicMessages(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::PublicMessageLoad* response);
    grpc::Status savePrivateMessage(::grpc::ServerContext* context, const ::net_service::PrivateMessageSave* request, ::net_service::Token* response);
    grpc::Status getPrivateMessages(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::PrivateMessageLoad* response);
};

inline void runServer()
{

    std::string server_address{ "localhost:55777" };
    ChatServer service;
    // Build server
    grpc::ServerBuilder server;

    server.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    server.RegisterService(&service);
    std::unique_ptr<grpc::Server> serverPtr{ server.BuildAndStart() };

    // Run server
    std::cout << "Server listening on " << server_address << std::endl;
    serverPtr->Wait();
}