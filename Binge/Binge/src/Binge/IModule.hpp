/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Imodule interface definition
*/

#pragma once

#include <map>

namespace Binge {

    class IModule {
	public:
        virtual std::string const getName() const = 0;
        virtual std::string const getAuthor() const = 0;
        virtual std::string const getIdentifier() const = 0;
        virtual std::string const getVersion() const = 0;
        virtual std::map<std::string, std::string> const getDependencies() const = 0;
        virtual void *getPackaged() const = 0;
        virtual void setDependency(IModule &) = 0;
        virtual IModule &getDependency(const std::string &) const = 0;
        virtual bool checkDependencies() const = 0;

	protected:
	private:
    };

} // namespace Binge
