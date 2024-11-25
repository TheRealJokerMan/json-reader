#
# Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
#

# Include the required modules.
include("FetchContent")

# Catch2.
if(BUILD_TESTING AND NOT TARGET Catch2::Catch2WithMain)
    FetchContent_Declare(Catch GIT_REPOSITORY "https://github.com/catchorg/Catch2.git" GIT_TAG "v3.7.1")
    FetchContent_MakeAvailable(Catch)
    list(APPEND CMAKE_MODULE_PATH "${catch_SOURCE_DIR}/extras")
endif(BUILD_TESTING AND NOT TARGET Catch2::Catch2WithMain)

# Doxygen.
if(BUILD_DOCS)
    find_package(Doxygen REQUIRED)
endif(BUILD_DOCS)

