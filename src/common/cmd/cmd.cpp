#include <cmd/cmd.h>

#include <chrono>
#include <semaphore>
#include <stdexcept>
#include <thread>

namespace os::cmd {

static std::vector<impl::Proc> procs;
static std::counting_semaphore<> sem(std::thread::hardware_concurrency() + 1);

namespace impl {

bool scan_procs() {
  bool result = false;
  for (auto iter = procs.begin(); iter != procs.end();) {
    if (impl::is_running(*iter)) {
      iter = procs.erase(iter);
      sem.release();
      result = true;
    } else {
      iter++;
    }
  }
  return result;
}
} // namespace impl

int run_cmd(const Cmd &cmd, Opt opt) {

  if (cmd.empty()) {
    throw std::runtime_error("Could not run empty command");
  }
  impl::scan_procs();

  while (!sem.try_acquire()) {
    logi("cmd process num too much,wait someone quit");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    impl::scan_procs();
  }

  impl::Proc proc = impl::create_proc(cmd, opt);

  if (!proc) {
    sem.release();
    throw std::runtime_error("create Process failed");
  }

  if (opt.wait_return) {
    impl::Result ret = impl::wait_proc(proc);
    sem.release();
    if (!ret) {
      // TODO: is this error handle right?
      throw std::system_category().message(ret.error());
    } else {
      return *ret;
    }
  } else {
    procs.push_back(proc);
  }

  return 0;
}

} // namespace os::cmd
