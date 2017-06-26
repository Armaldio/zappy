//
//-----------------------------------------------------------------------------
//Filename:    TCPSocket.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/21/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_TCPSOCKET_HPP
#define CLIENTQT_TCPSOCKET_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string>

namespace zappy {
class TCPSocket {
    protected:
        int _sock;
        sockaddr_in _addr;

    public:
        TCPSocket();

        virtual ~TCPSocket();

        bool create();

        //client initialization
        bool connect(const std::string host, const uint16_t port);

        //data transmission
        bool send(const std::string &) const;
        int recv (std::string &) const;

        bool isValid() const;

    void close();

    int getFd();
};
};

#endif //CLIENTQT_TCPSOCKET_HPP
