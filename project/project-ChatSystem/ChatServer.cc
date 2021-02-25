#pragma once 
 
#include <iostream>
#include "ChatServer.hpp"

// ./ChatServer tcp_port udp_port

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
}

