/*
  This file is part of KDToolBox.

  SPDX-FileCopyrightText: 2020-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Marc Mutz <marc.mutz@kdab.com>

  SPDX-License-Identifier: MIT
*/

#pragma once

#include <unordered_map>

#include <k20/detail/erase_if.h>

// like std::erase/_if
namespace k20
{
#if defined(__cpp_lib_erase_if) && _cpp_lib_erase_if >= 202002L // the version that returns size_type
using std::erase_if;

// std::experimental::erase_if isn't good enough: returns void
#else
template<typename UnaryPredicate, typename... Args>
typename std::unordered_map<Args...>::size_type erase_if(std::unordered_map<Args...> &c, UnaryPredicate pred)
{
    return detail::node_erase_if(c, pred);
}

template<typename UnaryPredicate, typename... Args>
typename std::unordered_multimap<Args...>::size_type erase_if(std::unordered_multimap<Args...> &c, UnaryPredicate pred)
{
    return detail::node_erase_if(c, pred);
}
#endif
} // namespace k20
