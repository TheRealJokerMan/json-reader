//
// Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
//

#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace json
{
    /// Specifies the type of token.
    enum class TokenType
    {
        BraceOpen,  ///< Opening brace.
        BraceClose, ///< Closing brace.
        String,     ///< String token.
    };

    /// Represents a token in an input stream.
    class Token final
    {
    public:
        /// Constructor.
        /// \param type The type of token.
        explicit Token(TokenType const type);

        /// Constructor.
        /// \param value The token value.
        explicit Token(std::string const value);

    private:
        TokenType m_type;
    };

    /// Converts an input stream into tokens.
    class Tokenizer final
    {
    public:
        /// Constructor.
        /// \param view The input stream.
        explicit Tokenizer(std::string const& view);

        /// Determines if there are any tokens remaining.
        /// \return true if there are any tokens remaining; false otherwise.
        [[nodiscard]] auto exhausted() const -> bool
        {
            return m_offset >= m_view.length();
        }

        /// Get the next token.
        /// \return A valid object on success; nothing otherwise.
        [[nodiscard]] auto next() -> std::optional<Token>;

    private:
        [[nodiscard]] auto read() -> char;
        [[nodiscard]] auto read_number(char const c) -> Token;
        [[nodiscard]] auto read_string() -> Token;

    private:
        std::string const& m_view;
        uint64_t           m_offset = 0;
        uint64_t           m_previous = 0;
    };
} // namespace json
