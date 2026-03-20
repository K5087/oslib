export module os.cmd;
import std;
namespace os {
namespace cmd {
using Cmd = std::vector<std::string>;
export std::string GetCommandStr(const Cmd& cmd);
namespace impl {
int run_cmd(const Cmd &cmd);
}
export int run_cmd(const Cmd &cmd);
} // namespace cmd

} // namespace os
