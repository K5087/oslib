#include <cmd/cmd.h>
#include <log/log.h>
#include <sys/wait.h>
#include <system_error>

namespace os::cmd::impl {
int run_cmd(const Cmd &cmd) {
  pid_t cpid = fork();
  if (cpid < 0) {
    throw std::system_error(errno, std::generic_category(),
                            "Could not fork child process");
  }
  if (cpid == 0) {
    std::vector<char *> argv;
    argv.reserve(cmd.size() + 1);
    for (auto &s : cmd) {
      argv.push_back(const_cast<char *>(s.c_str()));
    }
    argv.push_back(nullptr);
    execvp(argv[0], argv.data());
    perror("execvp");
    _exit(127);
  }
  if (cpid > 0) {
    int status = 0;
    if (waitpid(cpid, &status, 0) < 0) {
      throw std::system_error(errno, std::generic_category(), "waitpid failed");
    }
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    }
    return -1;
  }
  return -1;
}
} // namespace os::cmd::impl
