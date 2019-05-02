/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Binge class definition
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include "IModule.hpp"

namespace Binge {

    class Binge {
    public:
        Binge();
		~Binge();

        void addModule(const std::string &);
        void removeModule(const std::string &);
        void loadModules();
        IModule const &getModule(const std::string &) const;

	protected:
        bool _loaded;
        std::unordered_set<std::string> _modulesToLoad;
        std::vector<IModule *> _modulesLoaded;

	private:
    };

} // namespace Binge