#include <math.h>
#include "../vendor/minunit/minunit.h"
#include "../src/temp-converter.h"

const double epsilon = 1e-3;

char *
test_convert_fahrenheit_to_celsius(void) {
  mu_assert("expected fahr 32 to equal 0 celsius ",
            fabs(convert_fahrenheit_to_celsius(32)) < epsilon);
  return 0;
}
