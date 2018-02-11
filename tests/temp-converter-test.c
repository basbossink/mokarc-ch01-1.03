#include <math.h>
#include "../vendor/minunit/minunit.h"
#include "../src/temp-converter.h"

const double epsilon = 1e-3;

typedef struct temperature_pair {
  double fahrenheit;
  double celsius;
} temperature_pair;


#define TEST_CASE(f, c) { .fahrenheit = (f), .celsius = (c) },
static temperature_pair test_cases[] = {
    TEST_CASE(32, 0)
    TEST_CASE(33, 5.0 / 9.0)
    TEST_CASE(41, 5.0)
    TEST_CASE(23, -5.0)
    TEST_CASE(50, 10.0)
    TEST_CASE(59, 15.0)
    TEST_CASE(95, 35.0)
  };
#undef TEST_CASE


char *
test_convert_fahrenheit_to_celsius(void) {
  char const *message_format = "(%s:%s::%d) expected conversion of %f fahrenheit to equal %f celsius but got %f";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(temperature_pair);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    temperature_pair test = test_cases[i];
    double actual = convert_fahrenheit_to_celsius(test.fahrenheit);
    mu_assert(fabs(actual - test.celsius) < epsilon,
              message_format,
              __FILE__,
              __func__,
              i,
              test.fahrenheit,
              test.celsius,
              actual);
  }
  return 0;
}

char *
test_convert_celsius_to_fahrenheit(void) {
  char const* message_format = "(%s:%s::%d) expected conversion of %f celsius to equal %f fahrenheit but got %f";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(temperature_pair);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    temperature_pair test = test_cases[i];
    double actual = convert_celsius_to_fahrenheit(test.celsius);
    mu_assert(fabs(actual - test.fahrenheit) < epsilon,
      message_format,
      __FILE__,
      __func__,
      i,
      test.celsius,
      test.fahrenheit,
      actual);
  }
  return 0;
}
