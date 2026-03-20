#include <argp/argp.h>
#include <log/log.h>

using namespace os::argp;
int main(int argc, char *argv[]) {
  Parser parser;
  parser.add_rule({"-h"}, {Boundary::one_arg});
  parser.parse(argc, argv);
  return 0;
}
