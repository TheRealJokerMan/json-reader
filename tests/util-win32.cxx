//
// Copyright (c) 2024 Jamie Kenyon.
// SPDX-License-Identifier: MIT.
//

#include "util.hxx"

#include <processenv.h>

namespace com
{
    auto get_environment_variable(std::string_view const key) -> std::string
    {
        if (auto const length = GetEnvironmentVariableA(key.data(), nullptr, 0); length > 0)
        {
            std::string str;
            str.resize(length);
            str.resize(GetEnvironmentVariableA(key.data(), &str[0], length));
            return str;
        }

        return {};
    }
} // namespace com
