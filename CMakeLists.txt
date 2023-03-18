cmake_minimum_required(VERSION 3.8)

project("ChatCLI-server")

set(CMAKE_CXX_STANDARD 20)

set(SRCFILES ./main.cpp)

add_executable(ChatCLI-server ${SRCFILES})

find_package(gRPC CONFIG REQUIRED)