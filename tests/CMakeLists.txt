#
# Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
#

com_test(basic
    SOURCES
        "test-valid.cxx"
        $<$<PLATFORM_ID:Darwin,Linux>:util-posix.cxx>
        $<$<PLATFORM_ID:Windows>:util-win32.cxx>

    LIBRARIES
        com::json

    PROPERTIES
        ENVIRONMENT "ASSET_DIRECTORY=${CMAKE_CURRENT_SOURCE_DIR}/data/"
)
