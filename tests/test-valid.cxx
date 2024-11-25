//
// Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
//

#include <json-lib/document.hxx>
#include "util.hxx"

#include <catch2/catch_all.hpp>

namespace com
{
    TEST_CASE("Valid json files can be parsed", "[valid]")
    {
        auto const asset_directory = std::filesystem::path(get_environment_variable("ASSET_DIRECTORY"));
        auto const document        = json::load_document(asset_directory / "test-01.json");
    }

} // namespace com
