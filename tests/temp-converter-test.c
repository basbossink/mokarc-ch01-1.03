#include <math.h>
#include <stdio.h>
#include "../vendor/minunit/minunit.h"
#include "../src/temp-converter.h"

const double epsilon = 1e-3;

struct convert_fahrenheit_to_celsius_test_case {
  double fahrenheit;
  double expected;
};


#define FORMATTED_MESSAGE_SIZE_MAX 128
  static char message[FORMATTED_MESSAGE_SIZE_MAX];
#undef FORMATTED_MESSAGE_SIZE_MAX

char *
test_convert_fahrenheit_to_celsius(void) {

#define TEST_CASE(f, c) { .fahrenheit = (f), .expected = (c) },
  struct convert_fahrenheit_to_celsius_test_case test_cases[] = {
    TEST_CASE(32, 0)
    TEST_CASE(33, 5.0 / 9.0)
    TEST_CASE(41, 5.0)
    TEST_CASE(23, -5.0)
    TEST_CASE(50, 10.0)
    TEST_CASE(59, 15.0)
    TEST_CASE(95, 35.0)
  };
#undef TEST_CASE

  const char *message_format = "(%s:%s::%d) expected conversion of %f fahrenheit to equal %f celsius but got %f";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(struct convert_fahrenheit_to_celsius_test_case);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    struct convert_fahrenheit_to_celsius_test_case test = test_cases[i];
    double actual = convert_fahrenheit_to_celsius(test.fahrenheit);
    (void)snprintf(
      message,
      sizeof message,
      message_format,
      __FILE__,
      __func__,
      i,
      test.fahrenheit,
      test.expected,
      actual);
    mu_assert(message,
      fabs(actual - test.expected) < epsilon);
  }
  return 0;
}


struct convert_celsius_to_fahrenheit_test_case {
  double celsius;
  double expected;
};


char *
test_convert_celsius_to_fahrenheit(void) {

#define TEST_CASE(c, f) { .celsius = (c), .expected = (f) },
  struct convert_celsius_to_fahrenheit_test_case test_cases[] = {
    TEST_CASE(0, 32.0)
    TEST_CASE(5.0/9.0, 33.0)
    TEST_CASE(5, 41.0)
    TEST_CASE(-5.0, 23)
    TEST_CASE(10, 50.0)
    TEST_CASE(15, 59.0)
    TEST_CASE(35, 95.0)
  };
#undef TEST_CASE

  const char *message_format = "(%s:%s::%d) expected conversion of %f celsius to equal %f fahrenheit but got %f";
  const size_t number_of_test_cases = sizeof(test_cases) / sizeof(struct convert_celsius_to_fahrenheit_test_case);
  for (unsigned long i = 0ul;
       i < number_of_test_cases;
       i++) {
    struct convert_celsius_to_fahrenheit_test_case test = test_cases[i];
    double actual = convert_celsius_to_fahrenheit(test.celsius);
    (void)snprintf(
      message,
      sizeof message,
      message_format,
      __FILE__,
      __func__,
      i,
      test.celsius,
      test.expected,
      actual);
    mu_assert(message,
      fabs(actual - test.expected) < epsilon);
  }
  return 0;
}
