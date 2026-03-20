#include <argp/argp.h>
#include <cassert>
#include <iostream>

namespace os::argp {
void Parser::parse(int argc, char **argv) {
  bool get_one_arg = false;
  int i = 0;
  while (i < argc) {
  }
  for (int i = 0; i < argc; i++) {
    std::string_view arg = argv[i];
    if (!is_option(arg)) {
      other.push_back(std::string(arg));
      continue;
    }
    Rule &rule = rules[index[arg]];
    switch (rule.boundary) {
    case Boundary::get_self:
      args[i].push_back(std::string(arg));
      break;
    case Boundary::one_arg:
      if (i + 1 >= argc && is_option(argv[i + 1])) {
        throw std::invalid_argument(std::string(arg) + "need one param!");
      }
      args[i].push_back(argv[i + 1]);
      i++;
      break;
    case Boundary::another_rule:
      while (i + 1 < argc && !is_option(argv[i + 1])) {
        args[i].push_back(argv[i + 1]);
        i++;
      }
      break;
    }
  }
}

void Parser::add_option(const std::vector<std::string_view> &option,
                        const Rule &rule) {
  args.push_back({});
  rules.push_back(rule);

  std::vector<std::string> keys;
  keys.reserve(option.size());
  for (auto i : option) {
    keys.push_back(std::string(i));
  }
  options.push_back(keys);

  for (auto i : option) {
    assert(index.count(i) != 0);
    index.emplace(i, options.size());
  }
}

std::vector<std::string> &Parser::get_args(std::string_view key) {
  assert(index.count(key) != 0);
  return args[index[key]];
}

std::vector<std::string> &Parser::get_other() noexcept { return other; }

bool Parser::is_option(std::string_view arg) { return index.count(arg) != 0; }

void Parser::print_helper(std::string_view name, std::string_view key) {
  std::cout << "Usage: " << name;
  if (key != "") {
  }
}

} // namespace os::argp
