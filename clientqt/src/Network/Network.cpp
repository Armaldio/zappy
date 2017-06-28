//
//-----------------------------------------------------------------------------
//Filename:    Network.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/21/17.
//-----------------------------------------------------------------------------
//

#include <SFML/System/Thread.hpp>
#include <poll.h>
#include <iostream>
#include <sstream>
#include "Network/Network.hpp"



zappy::Network::Network() : _isRunning(false), _writerThread(nullptr), _readerThread(nullptr) {

}

zappy::Network::~Network() {
    if (_writerThread)
        delete(_writerThread);
    if (_readerThread)
        delete(_readerThread);
    _writerThread = nullptr;
    _readerThread = nullptr;
}

bool zappy::Network::newConnection(const std::string &host, const std::string &port) {
    for (auto c : port)
        if (!std::isdigit(c))
            return false;
    return newConnection(host, (const uint16_t) std::atoi(port.c_str()));
}

bool zappy::Network::newConnection(const std::string &host, const uint16_t port) {
    if (_socket.isValid())
        closeConnection();
    _socket.create();
    return _socket.connect(host, port);
}

void zappy::Network::closeConnection() {
    // stop
    _isRunning = false;
    _socket.close();

    send("local_exit");
    // wait
    if (_readerThread)
        _readerThread->join();
    if (_writerThread)
        _writerThread->join();
    delete(_readerThread);
    delete(_writerThread);
    _readerThread = nullptr;
    _writerThread = nullptr;
}

zappy::TCPSocket &zappy::Network::getSocket() {
    return _socket;
}

void zappy::Network::run() {
    if (_writerThread != nullptr || _readerThread != nullptr)
        return;
    _isRunning = true;
    _writerThread = new std::thread(&zappy::Network::_writer, this);
    _readerThread = new std::thread(&zappy::Network::_reader, this);
}

void zappy::Network::_writer() {
   std::cout << "Instance::_send -> run" << std::endl;
    std::string *buffer;
    while (_isRunning) {
            buffer = _outgoing.dequeue();
            if (buffer && (*buffer) != "local_exit") {
                _socket.send(*buffer);
                // std::cout << "send :" << *buffer << std::endl;
            }
    }
}

void zappy::Network::_reader() {
    std::cout << "Instance::_receive -> run" << std::endl;
    std::stringstream stream;
    std::string buf;

    pollfd pollfds[1];
    pollfds[0].fd = _socket.getFd();
    pollfds[0].events = POLLIN | POLLERR;

    int n = 0;

    while (_isRunning && _socket.isValid()) {
        n = poll(pollfds, 1, 500);

        if (n > 0) {
            if (pollfds[0].revents & POLLIN) {
                int ret = _socket.recv(buf);
                if (ret > 0) {
                    stream << buf;

                    // std::cout << "buffer: " <<  buf << std::endl;
                    while (std::getline(stream, buf,'\n') && !stream.eof()) {
                        // std::cout << "current buffer: " <<  buf << std::endl;
                        _incoming.enqueue(new std::string(buf));
                    }
                    if (stream.eof() && buf.size() > 0) {
                        stream.clear();
                        stream << buf;
                    }
                    else {
                        stream.clear();
                    }
                }
            }
        }
    }
}

void zappy::Network::send(std::string const &msg) {
    _outgoing.enqueue(new std::string(msg));
}

zappy::SafeQueue<std::string *> &zappy::Network::getIncoming() {
    return _incoming;
}
