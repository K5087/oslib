import os.argp
import std;
using namespace os::argp;
void print_args(std::string_view header, std::vector<std::string_view> &args) {

  std::cout << header << "--------------\n";
  for (auto &i : args) {
    std::cout << i << '\n';
  }
}
int main(int argc, char *argv[]) {
  Parser parser;
  parser.add_pos("input", "input file", Boundary::one_arg);
  parser.add_pos("output", "output file", Boundary::another_rule);
  parser.add_option({"-h","--help"}, "help message", Boundary::get_self);
  parser.add_option({"-v","--verbose"}, "verbose message", Boundary::another_rule);
  parser.parse(argc, argv);

  auto verbose = parser.get_args("-v");
  print_args("verbose", verbose);

  auto input = parser.get_pos(0);
  print_args("input", input);

  auto output = parser.get_pos(1);
  print_args("output", output);

  parser.print_helper("argp_test");
  return 0;
}
