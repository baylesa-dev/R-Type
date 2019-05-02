/*
** EPITECH PROJECT, 2018
** r-type
** File description:
** Network class definition
*/

#pragma once

#include "TCPServer.hpp"
#include "ServerHandler.hpp"

namespace Binge {

    class Network {
    public:
        Network();
        ~Network();
        template<typename ClientData>
        TCPServer<ClientData> *createTCPServer(const int port, const ServerHandler<ClientData> handler) const {
            return new TCPServer<ClientData>(port, handler);
        }

    protected:
    private:

    };

} // namespace Binge
