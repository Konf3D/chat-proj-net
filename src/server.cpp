#include "server.h"

grpc::Status ChatServer::signUp(::grpc::ServerContext* context, const::net_service::CredentialsSignUp* request, ::net_service::Token* response)
{
    
    return grpc::Status::OK;
}

grpc::Status ChatServer::signIn(::grpc::ServerContext* context, const::net_service::CredentialsSignIn* request, ::net_service::Token* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::signOff(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::Token* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::getName(::grpc::ServerContext* context, const::net_service::Uid* request, ::net_service::Uid* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::savePublicMessage(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::Token* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPublicMessagess(::grpc::ServerContext* context, const::net_service::MsgPos* request, ::net_service::PublicMessageLoad* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::savePrivateMessage(::grpc::ServerContext* context, const::net_service::Token* request, ::net_service::Token* response)
{
    return grpc::Status::OK;
}

grpc::Status ChatServer::getPrivateMessages(::grpc::ServerContext* context, const::net_service::MsgPos* request, ::net_service::PrivateMessageLoad* response)
{
    return grpc::Status::OK;
}
