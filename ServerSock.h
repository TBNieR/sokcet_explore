#pragma once
#include "Socket.h"
enum typeSock
{   
    block,
    unblock
};
class ServerSock :
    public Socket
{
public:
    ServerSock(int port,int connections,typeSock type = block);
    Socket* Accept();
};

