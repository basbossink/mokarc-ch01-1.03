#include <stdbool.h>
#include <getopt.h>

typedef struct option_flags {
    bool show_celsius_table;
    bool show_fahrenheit_table;
} option_flags;

typedef struct option option;

typedef void (*error_callback)(
    char *message);

typedef int (*getopt_long_fn)(
    int argc,
    char * const *argv,
    char const *optstring,
    const option *longopts,
    int *longindex);

option_flags parse_command_line(
    int argc,
    char* const *argv,
    getopt_long_fn getopt_fn,
    error_callback error_occurred);
