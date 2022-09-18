#ifndef _SOCKET_H_
#define _SOCKET_H_
#pragma once
#include <string>
#include <WinSock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
class Socket
{
public:
	Socket();
	Socket(SOCKET sock);
	virtual ~Socket();
	std::string ReceiveLine();
	bool SendLine(std::string);
	void close();
	bool getState();
	bool operator==(u_long code) {
		return ServerSocket == code;
	}
protected:
	SOCKET ServerSocket;
	bool state;
private:
	static bool isCreate;
};

#endif

