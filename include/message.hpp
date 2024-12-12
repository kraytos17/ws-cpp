#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include "opcode.hpp"

namespace ws {
    enum class MessageKind : std::int32_t {
        Text = std::to_underlying(OpCode::Text),
        Binary = std::to_underlying(OpCode::Binary)
    };

    struct MessageChunk {
        std::vector<std::uint8_t> payload;
        MessageChunk* next{nullptr};

        constexpr MessageChunk() = default;

        constexpr std::size_t payloadLen() const noexcept { return payload.size(); }
    };

    struct Message {
        MessageKind kind{};
        std::vector<MessageChunk> chunks;

        constexpr std::size_t totalPayloadLen() const noexcept {
            std::size_t totalLen{0};
            for (const auto& chunk: chunks) {
                totalLen += chunk.payloadLen();
            }
            return totalLen;
        }
    };
} // namespace ws
