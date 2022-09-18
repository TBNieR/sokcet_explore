#include "ServerSock.h"

ServerSock::ServerSock(int port, int connections, typeSock type)
{
	sockaddr_in addr = { 0 };
	addr.sin_family = PF_INET;
	addr.sin_port = htons(port);
	if (type == unblock) {
		u_long arg = 1;
		ioctlsocket(ServerSocket, FIONBIO,  &arg);//�����׽����Ƿ�����
	}
	if (SOCKET_ERROR==bind(ServerSocket,(sockaddr*)&addr,sizeof(sockaddr)))
	{
		close();
		throw "Bind Error";//��ʧ���׳��쳣
	}
	listen(ServerSocket, connections);
}

Socket* ServerSock::Accept()
{
	Socket* from_client_sock = new Socket(accept(ServerSocket, nullptr, nullptr));
	if (*from_client_sock == INVALID_SOCKET) {
		throw "Invalid socket";
	}//����ʧ��
	return from_client_sock;
}
