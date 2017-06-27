//
//-----------------------------------------------------------------------------
//Filename:    TCPSocket.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/21/17.
//-----------------------------------------------------------------------------
//

#include <cstring>
#include <iostream>
#include "Network/TCPSocket.hpp"

zappy::TCPSocket::TCPSocket() : _sock(-1) {

}

zappy::TCPSocket::~TCPSocket() {

}

bool zappy::TCPSocket::connect(const std::string host, const uint16_t port) {
    _addr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    _addr.sin_port = htons(port);
    /* Set the IP address to desired host to connect to */
    _addr.sin_addr.s_addr = inet_addr(host.c_str());

    return (::connect(_sock, (const sockaddr *) &_addr, sizeof(_addr)) >= 0);
}

bool zappy::TCPSocket::send(const std::string & buf) const {
    if (!isValid())
        return false;
    return ::send(_sock, buf.c_str(), buf.size(), 0) >= 0;
}

int zappy::TCPSocket::recv(std::string &s) const {
    char lbuffer[1024];

    if (!isValid())
        return false;

    ::bzero(lbuffer, 1024);

    int status = ::recv(_sock, lbuffer, 1023, 0);

    if(status == -1)
    {
        std::cout << "status == -1 errno == " << errno << " in Socket::recv\n";
        return 0;
    }
    else if(status == 0)
    {
        return 0;
    }
    else
    {
        s = lbuffer;
        return status;
    }
}

bool zappy::TCPSocket::isValid() const {
    return _sock != -1;
}

bool zappy::TCPSocket::create() {
    _sock = ::socket(AF_INET, SOCK_STREAM, 0);

    if (!isValid())
        return false;

    int on = 1;
    if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&on, sizeof(on)))
        return false;
    return false;
}

void zappy::TCPSocket::close() {
    if (isValid()) {
        ::close(_sock);
    }
    _sock = -1;
}

int zappy::TCPSocket::getFd() {
    return _sock;
}
