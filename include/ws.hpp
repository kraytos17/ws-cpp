#pragma once

namespace ws {
    template<typename Socket>
    struct Ws {
        Socket socket{};
        bool debug{false};
        bool client{false};
    };
} // namespace ws
