#include <cmd/cmd.h>

using namespace os::cmd;
int main(int argc, char *argv[]) {
#ifdef _WIN32
  Cmd cmd = {"cmd.exe", "/C", "echo", "hello,world"};
#else
  Cmd cmd = {"echo", "Hello,World"};
#endif // _WIN32
  auto ret = run_cmd(cmd);

  return ret.value_or(-1);
}
