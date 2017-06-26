//
//-----------------------------------------------------------------------------
//Filename:    Network.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/21/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_NETWORK_HPP
#define CLIENTQT_NETWORK_HPP

#include <include/Singleton.hpp>
#include <include/Network/TCPSocket.hpp>
#include <thread>
#include "SafeQueue.hpp"

namespace zappy {
    class Network : public Singleton<Network> {
    private:
        zappy::SafeQueue<std::string *> _incoming;
        zappy::SafeQueue<std::string *> _outgoing;
        std::mutex _receiveMutex;
        std::mutex _sendMutex;
        TCPSocket _socket;
        bool _isRunning;
        std::thread *_writerThread;
        std::thread *_readerThread;

    public:
        Network();

        virtual ~Network();

        bool newConnection(const std::string &host, const std::string &port);

        bool newConnection(const std::string &host, const uint16_t port);

        void closeConnection();

        void run();

        void send(std::string const& msg);

        TCPSocket &getSocket();

        zappy::SafeQueue<std::string *> & getIncoming();

    private:
        void _writer();

        void _reader();

        void _runner();
    };
};


#endif //CLIENTQT_NETWORK_HPP
