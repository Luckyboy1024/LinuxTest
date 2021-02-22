#pragma once 

#include <iostream>
#include "Log.hpp"

class SocketApi{
	public:
		static int Socket(int type)
		{
			int sock = socket(AF_INET, type, 0);
			if(sock < 0)
			{
				// 打印日志
				LOG("socket error!", ERROR);
				exit(1);
			}
		}
		static void Bind(int sock, int port)	// 绑定端口号和套接字
		{
			struct Sockaddr_in local;
			local.sin_family = AF_INET;
			local.sin_addr.s_addr = htonl(INADDR_ANY);  
			local.sin_port = htons(port);

			if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)	// 绑定失败
			{
				LOG("socket error", ERROR);
				exit(2);
			}
		}
		static void Listen(int sock)
		{

		}
}
