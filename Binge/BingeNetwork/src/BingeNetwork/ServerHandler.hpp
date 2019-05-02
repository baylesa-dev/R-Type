/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** ServerHandler type definition
*/

#pragma once

#include <functional>
#include "Handler.hpp"
#include "IServerClient.hpp"

namespace Binge {

    template<typename UserData>
    using ServerHandler = Handler<IServerClient<UserData> *>;

} // namespace Binge
