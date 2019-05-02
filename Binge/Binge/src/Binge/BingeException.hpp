/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** BingeException class definition
*/

#pragma once

#include <stdexcept>
#include <string>

namespace Binge {

    class BingeException : public std::runtime_error {
	public:
		explicit BingeException(const std::string &what_arg);
		explicit BingeException(const char *what_arg);
		~BingeException() noexcept;
        const char *what() const noexcept;

	protected:
	private:
        std::string _what;
    };

} // namespace Binge
