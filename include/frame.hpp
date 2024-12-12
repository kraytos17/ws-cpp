#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include "opcode.hpp"

namespace ws {
    struct Frame {
        std::vector<std::uint8_t> payload;
        OpCode opcode{};
        bool finish{false};

        constexpr Frame() = default;

        constexpr std::size_t payloadLen() const noexcept { return payload.size(); }
    };
} // namespace ws
