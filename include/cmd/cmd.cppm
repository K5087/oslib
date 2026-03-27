export module os.cmd;
import std;
namespace os::cmd {

export using Cmd = std::vector<std::string>;
export std::string GetCommandStr(const Cmd &cmd);
namespace impl {
int run_cmd(const Cmd &cmd);
}
export int run_cmd(const Cmd &cmd);

} // namespace os::cmd
