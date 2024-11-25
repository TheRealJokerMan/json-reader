//
// Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
//

#include "tokenizer.hxx"

#include <cctype>

namespace json
{
    Token::Token(TokenType const type) : m_type(type)
    {
    }

    Token::Token(std::string const value) : m_type(TokenType::String)
    {
    }

    Tokenizer::Tokenizer(std::string const& view) : m_view(view)
    {
    }

    auto Tokenizer::next() -> std::optional<Token>
    {
        if (exhausted())
            return std::nullopt;

        m_previous = m_offset;

        auto const c = read();
        switch (c)
        {
        case '"':
            return read_string();

        case '{':
            return Token(TokenType::BraceOpen);

        case '}':
            return Token(TokenType::BraceClose);

        default:
            if (c == '-' || (c >= '0' && c <= '9'))
                return read_number(c);
            break;
        }

        return {};
    }

    auto Tokenizer::read() -> char
    {
        char c = ' ';

        while (std::isspace(c) && !exhausted())
        {
            ++m_offset;
            c = m_view[m_offset];
        }

        return c;
    }

    auto Tokenizer::read_number(char const a) -> Token
    {
        std::string value = { a };
        char        c     = read();

        while (((c == '-') || (c >= '0' && c <= '9') || c == '.' || c == 'e') && !exhausted())
        {
            value += c;
            c = read();
        }

        return Token(TokenType::String);
    }

    auto Tokenizer::read_string() -> Token
    {
        std::string value;
        char        c = read();

        while (c != '"')
        {
            value += c;
            c = read();
        }

        return Token(TokenType::String);
    }

} // namespace json
