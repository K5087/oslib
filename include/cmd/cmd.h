#pragma once
#include <log/log.h>
#include <string>
#include <vector>

namespace os {
namespace cmd {
using Cmd = std::vector<std::string>;
std::string GetCommandStr(const Cmd& cmd);
namespace impl {
int run_cmd(const Cmd &cmd);
}
int run_cmd(const Cmd &cmd);
} // namespace cmd

} // namespace os
