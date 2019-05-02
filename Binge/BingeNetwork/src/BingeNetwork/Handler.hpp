/*
** EPITECH PROJECT, 2019
** R-Type
** File desBiption:
** Handler type definition
*/

#pragma once

#include <functional>

namespace Binge
{

    template<typename Param>
    using Handler = std::function<void(Param)>;

} // namespace Binge
