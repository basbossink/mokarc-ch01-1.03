#include <stdbool.h>
#include <getopt.h>

struct option_flags {
  bool show_celsius_table;
  bool show_fahrenheit_table;
};


typedef void (*error_callback)(const char* message);

typedef int (*getopt_long_fn)(
  int argc,
  char * const *argv,
  const char *optstring,
  const struct option *longopts,
  int *longindex);

struct option_flags
parse_command_line(
  int argc,
  char* const *argv,
  getopt_long_fn getopt_fn,
  error_callback error_occurred);
