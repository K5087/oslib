#include <cmd/cmd.h>

namespace os {
namespace cmd {
std::string GetCommandStr(const Cmd &cmd) {
  std::string command;
  for (size_t i = 0; i < cmd.size(); i++) {
    std::string_view arg = cmd[i];
    if (i > 0)
      command.append(" ");
    if (!arg.empty() &&
        std::string_view::npos == arg.find_first_of(" \t\n\v\"")) {
      command.append(arg);
    } else {
      command.append("\"");
      size_t backslashes = 0;
      for (size_t j = 0; j < arg.length(); ++j) {
        switch (arg[j]) {
        case '\\':
          backslashes += 1;
          break;
        case '\"':
          command.append(2 * backslashes + 1, '\\');
          backslashes = 0;
          command.push_back(arg[j]);
          break;
        default:
          command.append(backslashes, '\\');
          backslashes = 0;
          command.push_back(arg[j]);
          break;
        }
      }
      command.append(2 * backslashes, '\\');
      command.append("\"");
    }
  }
  return command;
}

int run_cmd(const Cmd &cmd) {
  if (cmd.empty()) {
    throw std::runtime_error("Could not run empty command");
  }
  return impl::run_cmd(cmd);
}
} // namespace cmd

} // namespace os
