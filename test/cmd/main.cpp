#include <cmd/cmd.h>

using namespace os::cmd;
int main(int argc, char *argv[]) {
  Cmd cmd = {"cmd.exe", "/C", "echo", "hello,world"};
  // Cmd cmd = {"echo", "Hello,World"};
  auto ret = run_cmd(cmd);

  return ret.value_or(-1);
}
