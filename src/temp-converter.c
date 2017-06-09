#include "temp-converter.h"

static const double zero_celsuis_in_fahrenheit = 32.0;
static const double fahrenheit_to_celsius_scaling_factor = 5.0/9.0;

double
convert_fahrenheit_to_celsius(double fahrenheit) {
  return fahrenheit_to_celsius_scaling_factor * (fahrenheit - zero_celsuis_in_fahrenheit);
}
