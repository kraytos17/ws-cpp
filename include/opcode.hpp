#pragma once

#include <cstdint>
#include <utility>

namespace ws {
    enum class OpCode : std::uint8_t {
        Continuation = 0x0,
        Text = 0x1,
        Binary = 0x2,
        Close = 0x8,
        Ping = 0x9,
        Pong = 0xA
    };

    constexpr bool isControl(OpCode opcode) noexcept {
        auto value = std::to_underlying(opcode);
        return value >= 0x8 && value <= 0xF;
    }
} // namespace ws
