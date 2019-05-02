/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** ServerClient class definition
*/

#pragma once

#include <string>
#include "IServerClient.hpp"
#include "ServerHandler.hpp"

namespace Binge {

    template<typename ClientData>
    class ServerClient : public IServerClient<ClientData> {
    public:
        ServerClient(const std::string &ip, const ServerHandler<ClientData> handler)
            : _ip(ip)
            , _handler(handler)
        {}
        virtual void start() = 0;
        virtual void close() = 0;
        virtual void send() = 0;
        const std::string &getIp() const {
            return this->_ip;
        }
        ClientData &getData() {
            return this->_data;
        }

    protected:
        std::string _ip;
        ClientData _data;
        ServerHandler<ClientData> _handler;
    };

} // namespace Binge
