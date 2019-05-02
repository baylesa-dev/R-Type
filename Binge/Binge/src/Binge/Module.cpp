/*
** EPITECH PROJECT, 2019
** R-Type
** File desBiption:
** Module class implementation
*/

#include "ModuleException.hpp"
#include "Module.hpp"

Binge::Module::Module()
    : _checked(false)
{
}

Binge::Module::~Module()
{
}

std::string const Binge::Module::getIdentifier() const {
    return this->getAuthor() + "@" + this->getName();
}

void Binge::Module::setDependency(IModule &module)
{
    bool inList = false;
    for (const auto [id, _]: this->getDependencies()) {
        if (id == module.getIdentifier())
            inList = true;
    }
    if (inList) {
        this->_dependencies.push_back(module);
        return;
    }
    throw ModuleException("Module '" + module.getIdentifier() +
        "' given to '" + this->getIdentifier() + "' was not a dependency.");
}

Binge::IModule &Binge::Module::getDependency(
    std::string const &identifier) const
{
    for (auto dep: this->_dependencies) {
        if (dep.first.getIdentifier() == identifier)
            return dep;
    }
    throw ModuleException("Dependency '" + identifier + "' needed by '" +
        this->getIdentifier() + "' is not satisfied!");
}

bool Binge::Module::checkDependencies() const
{
    for (const auto [depId, _]: this->getDependencies()) {
        bool resolved = false;
        for (const auto mod: this->_dependencies) {
            if (depId == mod.first.getIdentifier())
                resolved = true;
        }
        if (!resolved)
            throw ModuleException("Dependency '" + depId + "' needed by '"
                + this->getIdentifier() + "' is not satisfied!");
    }
    this->_checked = true;
}

bool Binge::Module::isVersionCompatible(const std::string &needed,
    const std::string &given)
{
    std::vector<std::string> slittedNeeded;
    std::vector<std::string> slittedGiven;
}
