/*
** EPITECH PROJECT, 2019
** R-Type
** File desBiption:
** IServer interface definition
*/

#pragma once

namespace Binge {

    template<typename ClientData>
    class IServer {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual const int getPort() const = 0;
    };

} // namespace Binge
