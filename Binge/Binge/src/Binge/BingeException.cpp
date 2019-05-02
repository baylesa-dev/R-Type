/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** BingeException class implementation
*/

#include <string>
#include "BingeException.hpp"

Binge::BingeException::BingeException(const std::string &what_arg)
    : std::runtime_error(what_arg)
    , _what(what_arg)
{
}

Binge::BingeException::BingeException(const char *what_arg)
    : std::runtime_error(what_arg)
    , _what(std::string(what_arg))
{
}

Binge::BingeException::~BingeException() noexcept
{
}

const char *Binge::BingeException::what() const noexcept
{
    return _what.c_str();
}