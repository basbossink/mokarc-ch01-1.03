#include <stdio.h>
#include <stdlib.h>

#include "../vendor/minunit/minunit.h"
#include "temp-converter-test.h"
#include "table-generator-test.h"
#include "command-line-parser-test.h"

int tests_run = 0;

static char* all_tests() {
    mu_run_test(test_command_line_parser);
    mu_run_test(test_convert_celsius_to_fahrenheit);
    mu_run_test(test_convert_fahrenheit_to_celsius);
    mu_run_test(test_table_generator);
    return 0;
}


int main(
    int argc,
    char **argv) {
    (void)argc;
    (void)argv;

    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
