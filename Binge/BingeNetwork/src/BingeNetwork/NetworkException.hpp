/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** NetworkException class definition
*/

#pragma once

#include "Binge/BingeException.hpp"

namespace Binge {

    class NetworkException : public BingeException {
    public:
        explicit NetworkException(const std::string &what_arg);
        explicit NetworkException(const char *what_arg);
        ~NetworkException() noexcept;
        const char *what() const noexcept;

    private:
        std::string _what;
    };

} // namespace Binge
