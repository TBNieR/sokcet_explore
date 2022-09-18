#include "Socket.h"
bool Socket::isCreate = false;
Socket::Socket()
{
    WSADATA Wsd;
    if (!isCreate)
    {
        if (WSAStartup(MAKEWORD(2, 2), &Wsd) != 0)
        {
            std::cout << "³õÊ¼»¯Ì×½Ó×Ö¶¯Ì¬¿âÊ§°Ü" << std::endl;
            state = false;
        }
        ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        isCreate = true;
    }

}

Socket::Socket(SOCKET sock)
{
    ServerSocket = sock;
}


Socket::~Socket()
{
    closesocket(ServerSocket);

}

std::string Socket::ReceiveLine()
{
    std::string ret;
    while (true)
    {
        char buf;
        switch (recv(ServerSocket,&buf,1,0))
        {
        case 0:
            return ret;
        case -1:
            return "";
        }
        ret += buf;
        if (buf == '\n'||buf==' ') {
            break;
        }
    }
    return ret;
}

bool Socket::SendLine(std::string buffer)
{
    buffer += '\n';
    return SOCKET_ERROR != send(ServerSocket, buffer.c_str(), buffer.length(), 0);
}

void Socket::close()
{

}

bool Socket::getState()
{
    return state;
}
