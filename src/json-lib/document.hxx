//
// Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
//

#pragma once

#include <filesystem>
#include <memory>

namespace json
{
    /// Represents a JSON document.
    class Document final
    {
    public:
        /// Constructor.
        /// \param buffer The contents of the file.
        explicit Document(std::string& buffer);

        /// Parse the document.
        /// \return true on success; false otherwise.
        [[nodiscard]] auto parse() -> bool;

    private:
        std::string m_buffer; ///< The contents of the file.
    };

    /// Load and parse a JSON document.
    /// \param path Fully-qualified path of a JSON file to load.
    /// \return A valid object on success; nothing otherwise.
    [[nodiscard]] auto load_document(std::filesystem::path const& path) -> std::unique_ptr<Document>;
} // namespace json
