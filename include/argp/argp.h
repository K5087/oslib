#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace os::argp {
class Arg{
    
};
class PosArg:public Arg{
    std::string help;
};

class OptArg:public Arg{
    std::string help;
};
class PairArg:public Arg{
    std::string help;
};
enum class Boundary {
  get_self,
  one_arg,
  another_rule,
};
struct Rule {
  Boundary boundary;

  std::string help;
};

class Parser {
public:
  void parse(int argc, char **argv);

  void add_option(const std::vector<std::string_view> &option,
                  const Rule &rule);

  std::vector<std::string> &get_args(std::string_view key);

  std::vector<std::string> &get_other() noexcept;

  void print_helper(std::string_view name, std::string_view key);

private:
  bool is_option(std::string_view arg);

private:
  std::vector<Rule> rules;
  std::vector<std::vector<std::string>> options;

  std::unordered_map<std::string_view, size_t> index;
  std::vector<std::vector<std::string>> args;
  std::vector<std::string> other;
};
} // namespace os::argp
