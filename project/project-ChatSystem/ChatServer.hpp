#pragma once 

#include <iostream>
#include <pthread.h>
#include "ProtocolUtil.hpp"

class ChatServer;

class Param{
	public:
		ChatServer *sp;
		int sock;
	public:
		Param(ChatServer *sp_, int &sock_) : sp(sp_), sock(sock_)
		~Param()
};

class ChatServer{
	private:
		int tcp_listen_sock;
		int tcp_port;
		int udp_work_sock; 
		int udp_port;
	public:
		ChatServer(int tcp_port_ = 8080, int udp_port_ = 8088):
			tcp_port(tcp_port_),
			tcp_listen_sock(-1),
			udp_port(udp_port_),
			udp_work_sock(-1)
		{}
		void InitServer()
		{
			tcp_listen_sock = SocketApi::Socket(SOCK_STREAM);
			udp_sock = SocketApi::Socket(SOCK_DGRAM);
			SocketApi::Bind(tcp_listen_sock, tcp_port);
			SocketApi::Bind(udp_work_sock, udp_port);

			SocketApi::Listen(tcp_listen_sock);
		}
		static void *HandlerRequest(void *arg)
		{
			Param *sp = (Param*)arg;
			int sock = p->sock;
			ChatServer *sp = p->sp;
			delete p;
			pthread_detach(pthread_self());

			// 读操作 recv:sock 
			// 分析 && 处理
			// 响应 response
			close(sock);
		}

		void Start()
		{
			std::string ip;
			int port;
			// 创建三个线程
			// pthread_t tid;
			// pthread_create(&tid, UserManager, );
			// pthread_create(&tid, RecvMessage, );
			// pthread_create(&tid, SendMessage, );
			for(;;){
				int sock = SocketApi::Accept(tcp_listen_sock, ip, port);
				if(sock > 0)
				{
					std::cout << "get a new client " << ip << " : " << port << std::endl;
					
					Param *p = new Param(this, sock);
					pthread_t tid;
					pthread_create(&tid, NULL, HandlerRequest, this);
					
				}
			}
		}
		~ChatServer()
		{

		}
};
