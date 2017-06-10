#include <math.h>
#include <stdio.h>
#include "../vendor/minunit/minunit.h"
#include "../src/temp-converter.h"

const double epsilon = 1e-3;

struct test_case {
  double fahrenheit;
  double expected;
};

char *
test_convert_fahrenheit_to_celsius(void) {

#define TEST_CASE(f, c) { .fahrenheit = (f), .expected = (c) },
  struct test_case test_cases[] = {
    TEST_CASE(32, 0)
    TEST_CASE(33, 5.0 / 9.0)
    TEST_CASE(41, 5.0)
  };
#undef TEST_CASE

#define FORMATTED_MESSAGE_SIZE_MAX 128
  static char message[FORMATTED_MESSAGE_SIZE_MAX];
#undef FORMATTED_MESSAGE_SIZE_MAX

  const char *message_format = "expected conversion of %f fahrenheit to equal %f celsius but got %f";
  for (int i = 0; i < sizeof(test_cases) / sizeof(struct test_case); i++) {
    struct test_case test = test_cases[i];
    double actual = convert_fahrenheit_to_celsius(test.fahrenheit);
    (void)sprintf(message, message_format, test.fahrenheit, test.expected, actual);
    mu_assert(message,
      fabs(actual - test.expected) < epsilon);
  }
  return 0;
}