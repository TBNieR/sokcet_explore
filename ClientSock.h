#pragma once
#include "Socket.h"
class ClientSock :
    public Socket
{
public:
    ClientSock(const std::string& host, int port);
    ~ClientSock();
};

