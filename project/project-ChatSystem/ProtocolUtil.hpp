#pragma once 
#include <iostream>

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

			if(bind(sock, (struct sockaddr*) & local, sizeof(local)) < 0)
			{
				LOG("socket error!", ERROR);
				exit(2);
			}
		}
		static void Listen(int sock)		// 监听
		{
			if(listen(sock, ) < 0)
			{
				LOG("Listen error!", ERROR);
				exit(3);
			}
		}
		static int Accept(int listen_sock)	    //获取新连接
		{
			struct 
			int sock = accept(listen_sock, )
		}
}
