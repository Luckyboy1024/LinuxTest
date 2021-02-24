#pragma once 

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "Log.hpp"

#define BACKLOG 5	// 设置底层全连接个数

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
			struct sockaddr_in local;
			local.sin_family = AF_INET;
			local.sin_addr.s_addr = htonl(INADDR_ANY);
			local.sin_port = htons(port);

			if(bind(sock, (struct sockaddr*) & local, sizeof(local)) < 0)	// 如果绑定失败
			{
				LOG("socket error!", ERROR);
				exit(2);
			}
		}
		static void Listen(int sock)		// 监听
		{
			if(listen(sock, BACKLOG) < 0)		// 全连接已经建立好的个数为 BACKLOG+1 个
			{
				LOG("Listen error!", ERROR);
				exit(3);
			}
		}
		static int Accept(int listen_sock, std::string &out_ip, int &out_port)	    //获取新连接
		{
			struct sockaddr_in peer;
			socklen_t len = sizeof(peer);
			int sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
			if(sock < 0)	// 获取失败
			{
				LOG("Accept error", WARNING);
				return -1;
			}
			out_ip = inet_ntoa(peer.sin_addr);
			out_port = htons(peer.sin_port);
			return sock;
		}
};
