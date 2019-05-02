/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** IServerClient interface definition
*/

#pragma once

#include <string>

namespace Binge {

    template<typename ClientData>
    class IServerClient {
    public:
        virtual void close() = 0;
        virtual void send() = 0;
        virtual const std::string &getIp() const = 0;
        virtual ClientData &getData() = 0;
    };

} // namespace Binge
