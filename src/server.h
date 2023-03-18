#pragma once
#include <grpc++/grpc++.h>
#include <iostream>
#include "../proto/net_service.grpc.pb.h"

class ChatServer : public net_service::net_service::Service
{
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