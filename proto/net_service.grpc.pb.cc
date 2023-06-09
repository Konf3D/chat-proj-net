// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: net_service.proto

#include "net_service.pb.h"
#include "net_service.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace net_service {

static const char* net_service_method_names[] = {
  "/net_service.net_service/signUp",
  "/net_service.net_service/signIn",
  "/net_service.net_service/signOff",
  "/net_service.net_service/savePublicMessage",
  "/net_service.net_service/getPublicMessages",
  "/net_service.net_service/savePrivateMessage",
  "/net_service.net_service/getPrivateMessages",
  "/net_service.net_service/getUsername",
};

std::unique_ptr< net_service::Stub> net_service::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< net_service::Stub> stub(new net_service::Stub(channel, options));
  return stub;
}

net_service::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_signUp_(net_service_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_signIn_(net_service_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_signOff_(net_service_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_savePublicMessage_(net_service_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getPublicMessages_(net_service_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_savePrivateMessage_(net_service_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getPrivateMessages_(net_service_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getUsername_(net_service_method_names[7], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status net_service::Stub::signUp(::grpc::ClientContext* context, const ::net_service::CredentialsSignUp& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::CredentialsSignUp, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_signUp_, context, request, response);
}

void net_service::Stub::async::signUp(::grpc::ClientContext* context, const ::net_service::CredentialsSignUp* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::CredentialsSignUp, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signUp_, context, request, response, std::move(f));
}

void net_service::Stub::async::signUp(::grpc::ClientContext* context, const ::net_service::CredentialsSignUp* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signUp_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncsignUpRaw(::grpc::ClientContext* context, const ::net_service::CredentialsSignUp& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::CredentialsSignUp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_signUp_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncsignUpRaw(::grpc::ClientContext* context, const ::net_service::CredentialsSignUp& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsignUpRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::signIn(::grpc::ClientContext* context, const ::net_service::CredentialsSignIn& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::CredentialsSignIn, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_signIn_, context, request, response);
}

void net_service::Stub::async::signIn(::grpc::ClientContext* context, const ::net_service::CredentialsSignIn* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::CredentialsSignIn, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signIn_, context, request, response, std::move(f));
}

void net_service::Stub::async::signIn(::grpc::ClientContext* context, const ::net_service::CredentialsSignIn* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signIn_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncsignInRaw(::grpc::ClientContext* context, const ::net_service::CredentialsSignIn& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::CredentialsSignIn, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_signIn_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncsignInRaw(::grpc::ClientContext* context, const ::net_service::CredentialsSignIn& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsignInRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::signOff(::grpc::ClientContext* context, const ::net_service::Token& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_signOff_, context, request, response);
}

void net_service::Stub::async::signOff(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signOff_, context, request, response, std::move(f));
}

void net_service::Stub::async::signOff(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_signOff_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncsignOffRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_signOff_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncsignOffRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsignOffRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::savePublicMessage(::grpc::ClientContext* context, const ::net_service::PublicMessageSave& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::PublicMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_savePublicMessage_, context, request, response);
}

void net_service::Stub::async::savePublicMessage(::grpc::ClientContext* context, const ::net_service::PublicMessageSave* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::PublicMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_savePublicMessage_, context, request, response, std::move(f));
}

void net_service::Stub::async::savePublicMessage(::grpc::ClientContext* context, const ::net_service::PublicMessageSave* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_savePublicMessage_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncsavePublicMessageRaw(::grpc::ClientContext* context, const ::net_service::PublicMessageSave& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::PublicMessageSave, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_savePublicMessage_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncsavePublicMessageRaw(::grpc::ClientContext* context, const ::net_service::PublicMessageSave& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsavePublicMessageRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::getPublicMessages(::grpc::ClientContext* context, const ::net_service::Token& request, ::net_service::PublicMessageLoad* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::Token, ::net_service::PublicMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getPublicMessages_, context, request, response);
}

void net_service::Stub::async::getPublicMessages(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::PublicMessageLoad* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::Token, ::net_service::PublicMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getPublicMessages_, context, request, response, std::move(f));
}

void net_service::Stub::async::getPublicMessages(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::PublicMessageLoad* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getPublicMessages_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::PublicMessageLoad>* net_service::Stub::PrepareAsyncgetPublicMessagesRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::PublicMessageLoad, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getPublicMessages_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::PublicMessageLoad>* net_service::Stub::AsyncgetPublicMessagesRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetPublicMessagesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::savePrivateMessage(::grpc::ClientContext* context, const ::net_service::PrivateMessageSave& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::PrivateMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_savePrivateMessage_, context, request, response);
}

void net_service::Stub::async::savePrivateMessage(::grpc::ClientContext* context, const ::net_service::PrivateMessageSave* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::PrivateMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_savePrivateMessage_, context, request, response, std::move(f));
}

void net_service::Stub::async::savePrivateMessage(::grpc::ClientContext* context, const ::net_service::PrivateMessageSave* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_savePrivateMessage_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncsavePrivateMessageRaw(::grpc::ClientContext* context, const ::net_service::PrivateMessageSave& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::PrivateMessageSave, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_savePrivateMessage_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncsavePrivateMessageRaw(::grpc::ClientContext* context, const ::net_service::PrivateMessageSave& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsavePrivateMessageRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::getPrivateMessages(::grpc::ClientContext* context, const ::net_service::Token& request, ::net_service::PrivateMessageLoad* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::Token, ::net_service::PrivateMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getPrivateMessages_, context, request, response);
}

void net_service::Stub::async::getPrivateMessages(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::PrivateMessageLoad* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::Token, ::net_service::PrivateMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getPrivateMessages_, context, request, response, std::move(f));
}

void net_service::Stub::async::getPrivateMessages(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::PrivateMessageLoad* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getPrivateMessages_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::PrivateMessageLoad>* net_service::Stub::PrepareAsyncgetPrivateMessagesRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::PrivateMessageLoad, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getPrivateMessages_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::PrivateMessageLoad>* net_service::Stub::AsyncgetPrivateMessagesRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetPrivateMessagesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status net_service::Stub::getUsername(::grpc::ClientContext* context, const ::net_service::Token& request, ::net_service::Token* response) {
  return ::grpc::internal::BlockingUnaryCall< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getUsername_, context, request, response);
}

void net_service::Stub::async::getUsername(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::Token* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getUsername_, context, request, response, std::move(f));
}

void net_service::Stub::async::getUsername(::grpc::ClientContext* context, const ::net_service::Token* request, ::net_service::Token* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getUsername_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::PrepareAsyncgetUsernameRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getUsername_, context, request);
}

::grpc::ClientAsyncResponseReader< ::net_service::Token>* net_service::Stub::AsyncgetUsernameRaw(::grpc::ClientContext* context, const ::net_service::Token& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetUsernameRaw(context, request, cq);
  result->StartCall();
  return result;
}

net_service::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::CredentialsSignUp, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::CredentialsSignUp* req,
             ::net_service::Token* resp) {
               return service->signUp(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::CredentialsSignIn, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::CredentialsSignIn* req,
             ::net_service::Token* resp) {
               return service->signIn(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::Token* req,
             ::net_service::Token* resp) {
               return service->signOff(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::PublicMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::PublicMessageSave* req,
             ::net_service::Token* resp) {
               return service->savePublicMessage(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::Token, ::net_service::PublicMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::Token* req,
             ::net_service::PublicMessageLoad* resp) {
               return service->getPublicMessages(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::PrivateMessageSave, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::PrivateMessageSave* req,
             ::net_service::Token* resp) {
               return service->savePrivateMessage(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::Token, ::net_service::PrivateMessageLoad, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::Token* req,
             ::net_service::PrivateMessageLoad* resp) {
               return service->getPrivateMessages(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      net_service_method_names[7],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< net_service::Service, ::net_service::Token, ::net_service::Token, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](net_service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::net_service::Token* req,
             ::net_service::Token* resp) {
               return service->getUsername(ctx, req, resp);
             }, this)));
}

net_service::Service::~Service() {
}

::grpc::Status net_service::Service::signUp(::grpc::ServerContext* context, const ::net_service::CredentialsSignUp* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::signIn(::grpc::ServerContext* context, const ::net_service::CredentialsSignIn* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::signOff(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::savePublicMessage(::grpc::ServerContext* context, const ::net_service::PublicMessageSave* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::getPublicMessages(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::PublicMessageLoad* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::savePrivateMessage(::grpc::ServerContext* context, const ::net_service::PrivateMessageSave* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::getPrivateMessages(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::PrivateMessageLoad* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status net_service::Service::getUsername(::grpc::ServerContext* context, const ::net_service::Token* request, ::net_service::Token* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace net_service

