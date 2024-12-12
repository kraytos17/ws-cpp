#pragma once

#include <cstdint>
namespace ws {
    enum class WsError : std::int32_t { ClientHandshakeError, SocketError, AllcatorError, ServerCloseError };
} // namespace ws
