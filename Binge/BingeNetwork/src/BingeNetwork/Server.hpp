/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Server abstract class definition
*/

#pragma once

#include "IServer.hpp"
#include "ServerHandler.hpp"

namespace Binge {

    template<typename ClientData>
    class Server : public IServer<ClientData> {
    public:
        Server(int port, const ServerHandler<ClientData> handler)
            : _port(port)
            , _handler(handler)
        {}
        virtual void start() = 0;
        virtual void stop() = 0;
        const int getPort() const {
            return this->_port;
        }

    protected:
        int _port;
        ServerHandler<ClientData> _handler;
    };

} // namespace Binge
