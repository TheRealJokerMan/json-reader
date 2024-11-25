//
// Copyright (c) 2024 Jamie Kenyon.
// SPDX-License-Identifier: MIT.
//

#include "util.hxx"

#include <cstdlib>

namespace com
{
    auto get_environment_variable(std::string_view const key) -> std::string
    {
        return std::getenv(key);
    }
} // namespace com
