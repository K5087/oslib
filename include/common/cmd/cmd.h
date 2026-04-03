#pragma once
#include <windows/cmd/cmd.h>

#include <log/log.h>
#include <string>
#include <vector>

namespace os::cmd {
using Cmd = std::vector<std::string>;

struct Opt {
  const char *fdin = nullptr;
  const char *fdot = nullptr;
  const char *fderr = nullptr;
  bool wait_return = true;
};

namespace impl {
// create a process to run command
Proc create_proc(const Cmd &cmd, const Opt &opt) noexcept;

// check process is running
bool is_running(Proc proc);

// check all created process have someone exit
bool check_procs();

// wait until process return
Result wait_proc(Proc proc);

} // namespace impl

// run an command
int run_cmd(const Cmd &cmd, Opt opt = {});

} // namespace os::cmd
