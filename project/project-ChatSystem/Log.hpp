#pragma once 

#include <iostream>
#include <string>

#define NORMAL 0
#define WARNING 1
#define ERROR 2

const char *log_level[] = {
	"Normal",
	"Warning",
	"Error",
	NULL,
}

void Log(std::string msg, int level, std::string file, int line)
{
	std::cout << '[' << msg << ']' << '[' << level << ']' << " : " << \
		file << " : " << line << std::endl; 

}

