
export module os.log;
typedef __builtin_va_list va_list;
namespace os {
namespace log {

export enum class Level {
  code,
  info,
  warn,
  erro,
};

const char *tostring(Level level);

namespace impl {

void log(Level level, const char *fmt, va_list args);

} // namespace impl

export void log(Level level, const char *fmt, ...);

} // namespace log

export void logc(const char *fmt, ...);

export void logi(const char *fmt, ...);

export void logw(const char *fmt, ...);

export void loge(const char *fmt, ...);

} // namespace os
