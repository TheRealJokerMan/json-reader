//
// Copyright (c) 2024 Jamie Kenyon.
// SPDX-License-Identifier: MIT.
//

#pragma once

#include <string>
#include <string_view>

namespace com
{
    /// Read the value of an environment variable.
    /// \param key The name of the environment variable.
    /// \return The value on success; nothing otherwise.
    [[nodiscard]] auto get_environment_variable(std::string_view const key) -> std::string;
} // namespace com
