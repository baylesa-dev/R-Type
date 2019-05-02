/*
** EPITECH PROJECT, 2019
** R-Type
** File desBiption:
** Binge class implementation
*/

#include "BingeException.hpp"
#include "Binge.hpp"

Binge::Binge::Binge()
    : _loaded(false)
{
}

Binge::Binge::~Binge()
{
}

void Binge::Binge::addModule(const std::string &modulePath)
{
    this->_modulesToLoad.insert(modulePath);
}

void Binge::Binge::removeModule(const std::string &modulePath)
{
    if (this->_modulesToLoad.count(modulePath) == 0)
        throw new BingeException("Cannot remove non added '" + modulePath + "' module.");
    this->_modulesToLoad.erase(modulePath);
}

void Binge::Binge::loadModules()
{
    if (!this->_loaded)
        throw BingeException("Modules are not loaded");
    for (const auto &name : this->_modulesToLoad)
    {
        //... Load module
        // Windows and linux
    }
    this->_loaded = false;
}

Binge::IModule const &Binge::Binge::getModule(const std::string &identifier) const
{
    for (const auto *module : this->_modulesLoaded)
    {
        if (module->getIdentifier() == identifier)
            return *module;
    }
    throw new BingeException("Module '" + identifier + "' is unknown");
}