#pragma once
#include <cmd/cmd.h>
#include <log/log.h>

namespace os::cmd::impl {
bool run_cmd(const std::vector<std::string> &cmd) {
  pid_t cpid = fork();
  if (cpid < 0) {
    log(ERRO, "Coull not fork child process: %s!", std::strerror(errno));
    return false;
  }
  if (cpid == 0) {
    // if ()
  }
}
} // namespace os::cmd::impl
