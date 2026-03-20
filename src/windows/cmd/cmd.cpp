module;
#include <windows.h>

module os.cmd;
import os.log;
import std;
namespace os::cmd::impl {
int run_cmd(const std::vector<std::string> &cmd) {
  STARTUPINFOA si = {sizeof(si)};
  PROCESS_INFORMATION pi;

  BOOL result = CreateProcessA(NULL, GetCommandStr(cmd).data(), NULL, NULL,
                               TRUE, 0, NULL, NULL, &si, &pi);
  if (!result) {
    loge("CreateProcess failed!");
    return false;
  }
  WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD ec;
  GetExitCodeProcess(pi.hProcess, &ec);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  return ec;
}
} // namespace os::cmd::impl
