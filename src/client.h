#pragma once
#include <grpc++/grpc++.h>
#include <iostream>
#include "../proto/net_service.grpc.pb.h"

class ChatClient {
public:
    ChatClient(std::shared_ptr<grpc::Channel> channel) : _stub{ net_service::net_service::NewStub(channel) } {}

    bool signUp(const std::string& login, const std::string& username, const std::string& password);
    bool signIn(const std::string& login, const std::string& password);
    void signOff();
    bool sendPublicMessage(const std::string& messageContent) const;
    bool sendPrivateMessage(const std::string& messageContent, const std::string& recieverUsername) const;
    bool loadMessages() const;
    
private:
    std::unique_ptr<net_service::net_service::Stub> _stub;
    net_service::Token _token;
    std::string _username;
};
class ChatGUI
{
public:
    ChatGUI();
    ~ChatGUI() = default;
public:
    void start();
private:
    void trySignIn();
    void trySignUp();
    void logged();
    ChatClient _client;
};

