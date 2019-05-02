/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** ModuleException class implementation
*/

#include <string>
#include "ModuleException.hpp"

Binge::ModuleException::ModuleException(const std::string &what_arg)
    : Binge::BingeException(what_arg)
    , _what(what_arg)
{
}

Binge::ModuleException::ModuleException(const char *what_arg)
    : Binge::BingeException(what_arg)
    , _what(std::string(what_arg))
{
}

Binge::ModuleException::~ModuleException() noexcept
{
}

const char *Binge::ModuleException::what() const noexcept
{
    return _what.c_str();
}