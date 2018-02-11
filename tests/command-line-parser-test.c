#include <stddef.h>
#include <stdlib.h>

#include "../vendor/minunit/minunit.h"
#include "../src/command-line-parser.h"

typedef struct command_line_parser_test_case {
    int argc;
    char *argv[2];
    getopt_long_fn getopt_impl;
    option_flags expected;
} command_line_parser_test_case;

void dummy_error_callback(
    char *message) {
    free(message);
}

int getopt_long_single_arg_stub(
    int argc,
    char * const *argv,
    char const *optstring,
    const struct option *longopts,
    int *longindex) {
    (void)argv;
    (void)optstring;
    (void)longopts;
    int retval;
    if(argc == 0) {
        retval = -1;
    } else if(*longindex < argc) {
        retval = argv[*longindex][0];
    } else {
        retval = -1;
    }
    (*longindex)++;
    return retval;
}

char* test_command_line_parser(void) {
    command_line_parser_test_case test_cases[] = {
        { .argc = 0,
          .argv = {""},
          .getopt_impl = getopt_long_single_arg_stub,
          .expected = {.show_celsius_table = false, .show_fahrenheit_table = true }},
        { .argc = 1,
          .argv = {"c"},
          .getopt_impl = getopt_long_single_arg_stub,
          .expected = {.show_celsius_table = true, .show_fahrenheit_table = false }},
        { .argc = 1,
          .argv = {"f"},
          .getopt_impl = getopt_long_single_arg_stub,
          .expected = {.show_celsius_table = false, .show_fahrenheit_table = true }},
        { .argc = 2,
          .argv = {"c", "f"},
          .getopt_impl = getopt_long_single_arg_stub,
          .expected = {.show_celsius_table = true, .show_fahrenheit_table = true }}};

    char const *message_format = "(%s:%s:%d) expected command line parse of %s to equal %d, %d but got %d, %d";
    const size_t number_of_test_cases = sizeof(test_cases) / sizeof(command_line_parser_test_case);
    for (unsigned long i = 0ul;
         i < number_of_test_cases;
         i++) {
        command_line_parser_test_case test = test_cases[i];
        option_flags actual = parse_command_line(
            test.argc,
            test.argv,
            test.getopt_impl,
            dummy_error_callback);
        mu_assert(
            actual.show_celsius_table == test.expected.show_celsius_table &&
            actual.show_fahrenheit_table == test.expected.show_fahrenheit_table,
            message_format,
            __FILE__,
            __func__,
            i,
            test.argc > 0 ? test.argv[0] : "",
            test.expected.show_celsius_table,
            test.expected.show_fahrenheit_table,
            actual.show_celsius_table,
            actual.show_fahrenheit_table);
    }
    return 0;
}
