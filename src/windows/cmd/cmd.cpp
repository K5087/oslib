#include <cmd/cmd.h>
#include <log/log.h>
#include <windows.h>

namespace os::cmd {
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

namespace impl {
Proc create_proc(const Cmd &cmd, const Opt &opt) noexcept {
  STARTUPINFO si = {sizeof(si)};
  PROCESS_INFORMATION pi;

  BOOL result = CreateProcess(NULL, GetCommandStr(cmd).data(), NULL, NULL, TRUE,
                              0, NULL, NULL, &si, &pi);
  if (!result) {
    return Proc(nullptr);
  }
  CloseHandle(pi.hThread);
  return Proc(pi.hProcess);
}

bool is_running(Proc proc) {
  if (!proc) {
    return false; // is must need?
  }
  DWORD result = WaitForSingleObject(proc, 0);
  if (result == WAIT_TIMEOUT) {
    return true;
  }

  return false;
}

Result wait_proc(Proc proc) {
  DWORD result = WaitForSingleObject(proc, INFINITE);
  if (result == WAIT_FAILED) {
    loge("couldn't wait child procress");
    return Reason(GetLastError());
  }
  DWORD exit_status;
  if (!GetExitCodeProcess(proc, &exit_status)) {
    loge("couldn't get child process exit code");
    return Reason(GetLastError());
  }
  CloseHandle(proc);
  return exit_status;
}

} // namespace impl
} // namespace os::cmd
