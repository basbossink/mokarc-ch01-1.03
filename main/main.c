#include <stdio.h>
#include "../src/table-generator.h"
#include "../src/temp-converter.h"

int
main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  const double lower = 0.0;
  const double upper = 300.0;
  const double step = 20.0;

  generate_table(
    lower,
    upper,
    step,
    convert_fahrenheit_to_celsius,
    puts);
}
