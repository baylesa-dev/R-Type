/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Module class definition
*/

#pragma once

#include <vector>
#include <map>
#include <string>
#include "IModule.hpp"

namespace Binge {

    class Module : public IModule {
	public:
		Module();
		~Module();
        virtual std::string const getName() const = 0;
        virtual std::string const getAuthor() const = 0;
        virtual std::string const getVersion() const = 0;
        virtual std::map<std::string, std::string>
            const getDependencies() const = 0;
        virtual void *getPackaged() const = 0;
        std::string const getIdentifier() const;
        void setDependency(IModule &) final;
        IModule &getDependency(const std::string &) const final;
        bool checkDependencies() const final;
        static bool isVersionCompatible(const std::string &,
            const std::string &);
	protected:
	private:
        bool _checked;
        std::map<std::string, IModule> _dependencies;
    };

} // namespace Binge
