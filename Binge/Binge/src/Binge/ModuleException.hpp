/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** ModuleException class definition
*/

#pragma once

#include "BingeException.hpp"

namespace Binge {

    class ModuleException : public BingeException {
	public:
		explicit ModuleException(const std::string &what_arg);
		explicit ModuleException(const char *what_arg);
        ~ModuleException() noexcept;
        const char *what() const noexcept;

	protected:
	private:
        std::string _what;
    };

} // namespace Binge
