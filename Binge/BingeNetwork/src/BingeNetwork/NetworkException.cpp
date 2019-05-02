/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** NetworkException class implementation
*/

#include <string>
#include "NetworkException.hpp"

Binge::NetworkException::NetworkException(const std::string &what_arg)
    : Binge::BingeException(what_arg)
    , _what(what_arg)
{
}

Binge::NetworkException::NetworkException(const char *what_arg)
    : Binge::BingeException(what_arg)
    , _what(std::string(what_arg))
{
}

Binge::NetworkException::~NetworkException() noexcept
{
}

const char *Binge::NetworkException::what() const noexcept
{
    return _what.c_str();
}