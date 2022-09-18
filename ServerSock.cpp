#include "ServerSock.h"

ServerSock::ServerSock(int port, int connections, typeSock type)
{
	sockaddr_in addr = { 0 };
	addr.sin_family = PF_INET;
	addr.sin_port = htons(port);
	if (type == unblock) {
		u_long arg = 1;
		ioctlsocket(ServerSocket, FIONBIO,  &arg);//设置套接字是否阻塞
	}
	if (SOCKET_ERROR==bind(ServerSocket,(sockaddr*)&addr,sizeof(sockaddr)))
	{
		close();
		throw "Bind Error";//绑定失败抛出异常
	}
	listen(ServerSocket, connections);
}

Socket* ServerSock::Accept()
{
	Socket* from_client_sock = new Socket(accept(ServerSocket, nullptr, nullptr));
	if (*from_client_sock == INVALID_SOCKET) {
		throw "Invalid socket";
	}//接收失败
	return from_client_sock;
}
