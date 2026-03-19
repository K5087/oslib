#include <cmd/cmd.h>

using namespace os::cmd;
int main(int argc, char *argv[]) {
  Cmd cmd = {"echo", "hello,world"};
  return run_cmd(cmd);
}
