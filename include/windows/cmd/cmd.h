#pragma once

#include <Result.hpp>
namespace os::cmd {

// HANDLE
using Proc = void *;
namespace impl  {
using Result = os::handle::Result<int,unsigned long>;
using Reason = os::handle::Reason<unsigned long>;
}
} // namespace moke::cmd
