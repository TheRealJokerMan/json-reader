#
# Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
#

# Set the minimum CMake version.
cmake_minimum_required(VERSION 3.28.0 FATAL_ERROR)

# Include pre-project definitions.
include("toolchain-defaults")

# Define the project.
project(JsonReader
    VERSION         0.0.1.0
    DESCRIPTION     "JSON reader"
    HOMEPAGE_URL    "https://www.jamiekenyon.com/"
    LANGUAGES       CXX
)

# Include the dependent modules.
include("deployment")
include("options")
include("packages")
include("targets")

# Add the sources.
add_subdirectory("src")

# Enable testing.
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory("tests")
endif()
