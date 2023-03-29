// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <grpc++/grpc++.h>
#include <string>
#include <memory>
#include <iostream>
#include <thread>
#include "server.h"
#include "client.h"

int main()
{
	static char answer;
	std::cout << "Run as server ? [Y/N]\n";
	
	std::cin >> answer;
	if (answer == 'Y')
		runServer();
	else
		ChatGUI().start();
}