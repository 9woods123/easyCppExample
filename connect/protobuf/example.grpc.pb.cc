// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: example.proto

#include "example.pb.h"
#include "example.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* ExampleService_method_names[] = {
  "/ExampleService/AddNumbers",
};

std::unique_ptr< ExampleService::Stub> ExampleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ExampleService::Stub> stub(new ExampleService::Stub(channel));
  return stub;
}

ExampleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_AddNumbers_(ExampleService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ExampleService::Stub::AddNumbers(::grpc::ClientContext* context, const ::AddRequest& request, ::AddResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AddRequest, ::AddResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddNumbers_, context, request, response);
}

void ExampleService::Stub::experimental_async::AddNumbers(::grpc::ClientContext* context, const ::AddRequest* request, ::AddResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AddRequest, ::AddResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddNumbers_, context, request, response, std::move(f));
}

void ExampleService::Stub::experimental_async::AddNumbers(::grpc::ClientContext* context, const ::AddRequest* request, ::AddResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddNumbers_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AddResponse>* ExampleService::Stub::PrepareAsyncAddNumbersRaw(::grpc::ClientContext* context, const ::AddRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AddResponse, ::AddRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddNumbers_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AddResponse>* ExampleService::Stub::AsyncAddNumbersRaw(::grpc::ClientContext* context, const ::AddRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddNumbersRaw(context, request, cq);
  result->StartCall();
  return result;
}

ExampleService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ExampleService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ExampleService::Service, ::AddRequest, ::AddResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ExampleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AddRequest* req,
             ::AddResponse* resp) {
               return service->AddNumbers(ctx, req, resp);
             }, this)));
}

ExampleService::Service::~Service() {
}

::grpc::Status ExampleService::Service::AddNumbers(::grpc::ServerContext* context, const ::AddRequest* request, ::AddResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

