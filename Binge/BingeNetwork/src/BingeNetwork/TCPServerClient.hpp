/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** TCPServerClient definition and implementation
*/

#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "ServerClient.hpp"
#include "ServerHandler.hpp"

namespace Binge {

    template<typename ClientData>
    class TCPServerClient : public std::enable_shared_from_this<TCPServerClient<ClientData>>,
        public ServerClient<ClientData> {
    public:
        TCPServerClient(boost::asio::ip::tcp::socket socket,
            const std::string &ip,
            const ServerHandler<ClientData> handler)
                : _socket(std::move(socket))
                , ServerClient<ClientData>(ip, handler) {
                //debug
                std::cout << "New client with ip : " << ip << std::endl;
            }

        ~TCPServerClient() {
            this->close();
        }

        void start() {
            read();
        }

        void close() {
            if (this->_socket.is_open())
                this->_socket.close();
        }

        void send() {
            auto self(std::enable_shared_from_this<TCPServerClient<ClientData>>::
                shared_from_this());
            boost::asio::async_write(this->_socket,
                boost::asio::buffer(this->_buffer),
                [this, self](boost::system::error_code err, int len) {});
        }

        char _buffer[128];

    protected:
        void read() {
            auto self(std::enable_shared_from_this<TCPServerClient<ClientData>>::
                shared_from_this());
            this->_socket.async_read_some(boost::asio::buffer(this->_buffer, 128),
                [this, self](boost::system::error_code err, int len) {
                if (!err) {
                    this->_handler(&(*this));
                    //debug
                    this->_buffer[0] = 'O';
                    this->_buffer[1] = 'K';
                    this->_buffer[2] = '\0';
                    this->send();
                }
                this->read();
            });
        }

        boost::asio::ip::tcp::socket _socket;
    };

} // namespace Binge
