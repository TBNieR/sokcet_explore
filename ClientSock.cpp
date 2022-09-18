#include "ClientSock.h"

ClientSock::ClientSock(const std::string& host, int port)
{
    using namespace std;
    int RetVal;
    state = true;
    hostent* hst = gethostbyname(host.c_str());
    if (ServerSocket == INVALID_SOCKET)
    {
        cout << "�����׽���ʧ��" << endl;
        state = false;
        WSACleanup();
    }

    SOCKADDR_IN ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    ServerAddr.sin_addr = *((in_addr*)hst->h_addr_list[0]);
    RetVal = connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (RetVal == SOCKET_ERROR)
    {
        cout << "���ӷ�����ʧ��" << endl;
        state = false;
    }
}

ClientSock::~ClientSock()
{

    WSACleanup();
}
