# Python Client
import grpc
from example_pb2 import Request, Response
from example_pb2_grpc import MyServiceStub

def call_cpp_service():
    # Create a gRPC channel
    channel = grpc.insecure_channel('localhost:50051')

    # Create a gRPC stub
    stub = MyServiceStub(channel)

    # Create a request
    request = Request()

    # Call the C++ service
    response = stub.MyFunction(request)

    # Process the response
    print(response)

if __name__ == '__main__':
    call_cpp_service()

