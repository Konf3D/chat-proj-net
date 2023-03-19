cmake_minimum_required(VERSION 3.8)

project("ChatCLI-server")

set(CMAKE_CXX_STANDARD 20)

set(SRCFILES ./src/main.cpp ./src/client.cpp ./src/server.cpp)

add_executable(ChatCLI-server ${SRCFILES})

# this is heuristically generated, and may not be correct
find_package(gRPC CONFIG REQUIRED)
# note: 7 additional targets are not displayed.
target_link_libraries(ChatCLI-server PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts)