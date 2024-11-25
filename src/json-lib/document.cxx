//
// Copyright (c) 2024 Jamie Kenyon. SPDX-License-Identifier: MIT.
//

#include "document.hxx"
#include "detail/tokenizer.hxx"

#include <fstream>

namespace json
{
    Document::Document(std::string& buffer) : m_buffer(std::move(buffer))
    {
    }

    auto Document::parse() -> bool
    {
        Tokenizer tokenizer(m_buffer);

        while (!tokenizer.exhausted())
        {
            if (auto const token = tokenizer.next(); token)
            {
            }
        }

        return false;
    }

    auto load_document(std::filesystem::path const& path) -> std::unique_ptr<Document>
    {
        if (std::ifstream reader(path, std::ios::in | std::ios::ate); reader)
        {
            std::string buffer;

            buffer.resize(reader.tellg());
            reader.seekg(std::ios::beg);
            reader.read(&buffer[0], buffer.size());

            auto document = std::make_unique<Document>(buffer);
            return document->parse() ? std::move(document) : nullptr;
        }

        return nullptr;
    }
} // namespace json
