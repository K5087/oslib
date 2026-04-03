#pragma once
#include <expected>

namespace os::handle {
template <class Ty, class Err> using Result = std::expected<Ty, Err>;
template <class Err> using Reason = std::unexpected<Err>;
} // namespace os::handle
