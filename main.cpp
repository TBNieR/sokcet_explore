#include "ClientSock.h"
#include "ServerSock.h"
#include <thread>
#include <string>
#include <fstream>
	
void client_connect(Socket *accept) {
	std::ifstream f_ptr;
	f_ptr.open("./index.html",std::ios::in);
	if (f_ptr.is_open())
	{
		std::string buf;
		while (std::getline(f_ptr, buf))
		{
			accept->SendLine(buf);
		}
	}
	while (true)
	{
		std::string buffer = accept->ReceiveLine();
		if (buffer.empty())
			break;
		std::cout << buffer;
	}
	delete accept;
}
int main(int args, const char* argc[])
{
	/*try
	{
		ClientSock socket("www.baidu.com", 80);
		socket.SendLine("GET / HTTP/1.0");
		socket.SendLine("Host: www.baidu.com");
		socket.SendLine("");

		while (socket.getState())
		{
			std::string buf = socket.ReceiveLine();
			if (buf.empty()) {
				break;
			}
			std::cout << buf;
		}
	}
	catch (const std::exception& error_msg)
	{
		std::cout << error_msg.what() << std::endl;
	}*/
	try
	{
		ServerSock  server(80, 10);
		while (server.getState())
		{
			Socket* accept_ = server.Accept();
			std::thread th(client_connect,accept_);
			th.detach();
		}
	}
	catch (const std::exception& error_msg)
	{
		std::cout << error_msg.what() << std::endl;
	}
	return 0;
}