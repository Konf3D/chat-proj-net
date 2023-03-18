#pragma once
#include <grpc++/grpc++.h>
#include <iostream>
#include "../proto/net_service.grpc.pb.h"

class ChatClient {
public:
    ChatClient(std::shared_ptr<grpc::Channel> channel) : _stub{ net_service::net_service::NewStub(channel) } {}

private:
    std::unique_ptr<net_service::net_service::Stub> _stub;
};

inline void runClient()
{

}