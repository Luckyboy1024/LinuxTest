#pragma once 
#include <iostream>

class SocketApi{
	public:
		static int Socket(int type)
		{
			int sock = socket(AF_INET, type, 0);
			if(sock < 0)
			{

			}
		}
}
