#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "../src/table-generator.h"
#include "../src/temp-converter.h"
#include "../src/command-line-parser.h"

static char const* fahrenheit_row_format = "| %14.0f | %11.1f |";
static char const* fahrenheit_table_header = "\n"\
    "| Temperature conversion table |\n"\
    "+------------------------------+\n"\
    "|   Fahrenheit   |   Celsius   |\n"\
    "+----------------+-------------+";


static char const* celsius_row_format = "| %11.0f | %14.1f |";
static char const* celsius_table_header = "\n"\
    "| Temperature conversion table |\n"\
    "+------------------------------+\n"\
    "|   Celsius   |  Fahrenheit    |\n"\
    "+-------------+----------------+";

void usage(
    char* error_text) {
    printf(
        "temp_table \n"\
        "Prints temperature conversion tables between Celsius and Fahrenheit,\n"\
        "and vice versa.\n"\
        "\n%s\n"\
        "Usage:\n"\
        "    temptable [-c|--celsius] [-f|--fahrenheit]\n\n",
        error_text);
    free(error_text);
    exit(EXIT_FAILURE);
}

int main(
    int argc,
    char * const *argv) {
    const double lower = 0.0;
    const double upper = 300.0;
    const double step = 20.0;

    option_flags parsed = parse_command_line(argc, argv, getopt_long, usage);
    bool const both = parsed.show_fahrenheit_table && parsed.show_celsius_table;
    if(parsed.show_fahrenheit_table) {
        generate_table(
            lower,
            upper,
            step,
            fahrenheit_table_header,
            fahrenheit_row_format,
            convert_fahrenheit_to_celsius,
            puts);
    }
    if(both) { puts(""); }
    if(parsed.show_celsius_table) {
        generate_table(
            lower,
            upper,
            step,
            celsius_table_header,
            celsius_row_format,
            convert_celsius_to_fahrenheit,
            puts);
    }
}
