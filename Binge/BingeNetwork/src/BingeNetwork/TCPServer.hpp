/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** TCPServer class definition and implementation
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "Server.hpp"
#include "ServerHandler.hpp"
#include "TCPServerClient.hpp"
#include "NetworkException.hpp"

boost::asio::io_service io_service_g;

namespace Binge {

    template<typename ClientData>
    class TCPServer : public Server<ClientData> {
    public:
        TCPServer(int port, const ServerHandler<ClientData> handler)
            : _acceptor(io_service_g, boost::asio::ip::tcp::endpoint(
                boost::asio::ip::tcp::v4(), port))
            , _socket(io_service_g)
            , Server<ClientData>(port, handler)
        {}

        ~TCPServer() {
            if (this->_started)
                stop();
        }

        void start() {
            if (this->_started)
                throw NetworkException(
                    "Server: Server already started");
            this->accept();
            this->_started = true;
            io_service_g.run();
        }

        void stop() {
            if (!this->_started)
                throw NetworkException(
                    "Server: Server already stoped");
            //...
            this->_started = false;
        }

    protected:
        void accept() {
            this->_acceptor.async_accept(this->_socket,
                [this](boost::system::error_code err)
            {
                if (!err) {
                    std::string ip(this->_socket.remote_endpoint()
                        .address().to_string());
                    std::make_shared<TCPServerClient<ClientData>>(
                        std::move(this->_socket), ip,
                        this->_handler)->start();
                }
                this->accept();
            });
        }

        bool _started;
        boost::asio::ip::tcp::socket _socket;
        boost::asio::ip::tcp::acceptor _acceptor;
    };

} // namespace Binge
