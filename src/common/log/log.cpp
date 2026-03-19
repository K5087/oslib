#include <log/log.h>

#include <cstdarg>
#include <cstdio>

namespace os {
namespace log {

const char *tostring(Level level) {
  switch (level) {
  case Level::code:
    return "code";
  case Level::info:
    return "info";
  case Level::warn:
    return "warn";
  case Level::erro:
    return "erro";
  default:
    return "unkn";
  }
}
namespace impl {
void log(Level level, const char *fmt, va_list args) {
  std::fprintf(stderr, "[%s]", tostring(level));
  std::vfprintf(stderr, fmt, args);
  std::putc('\n', stderr);
}
} // namespace impl

void log(Level level, const char *fmt, ...) {
  va_list list;
  va_start(list, fmt);
  impl::log(level, fmt, list);
  va_end(list);
}

} // namespace log

void logc(const char *fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log::impl::log(log::Level::code, fmt, list);
  va_end(list);
}

void logi(const char *fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log::impl::log(log::Level::info, fmt, list);
  va_end(list);
}

void logw(const char *fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log::impl::log(log::Level::warn, fmt, list);
  va_end(list);
}

void loge(const char *fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log::impl::log(log::Level::erro, fmt, list);
  va_end(list);
}

} // namespace os
