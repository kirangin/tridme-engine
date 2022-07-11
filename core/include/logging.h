#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
#include <ctime>
#include <string>

namespace Tridme {

	#define SUCCESS 0
	#define WARNING 1
	#define ERROR   2
	#define INFO    3

	void LOG(int type, std::string s);
	
}

#endif