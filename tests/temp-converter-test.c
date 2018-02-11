#include <stdbool.h>
#include <math.h>

#include "../vendor/minunit/minunit.h"
#include "../src/temp-converter.h"

/**
 * Definitions
 */
const double epsilon = 1e-3;

typedef struct temperature_pair {
    double fahrenheit;
    double celsius;
} temperature_pair;

typedef char* (*test_single_case)(
    temperature_pair test_case,
    unsigned long test_case_counter);

/**
 * Helpers
 */
static bool approximately_equal(
    double actual,
    double expected) {
    return fabs(actual - expected) < epsilon;
}

static char* run_tests(
    temperature_pair test_cases[],
    test_single_case test_it) {
    char* result = NULL;
    for (unsigned long i = 0ul;
         !isnan(test_cases[i].fahrenheit) && !result;
         i++) {
        temperature_pair test = test_cases[i];
        result = test_it(test, i);
    }
    return result;
}

#define single_test(fromL,toL,conversion) static char* single_from_##fromL(\
    temperature_pair pair,\
    unsigned long test_case_counter) {\
    char const *message_format = "(%s:%s::%d) expected conversion of %f " #fromL " to equal %f " #toL " but got %f";\
    double fahrenheit = pair.fahrenheit;\
    double celsius = pair.celsius;\
    double actual = conversion(fromL);\
    mu_assert(\
        approximately_equal(actual, toL),\
        message_format,\
        __FILE__,\
        __func__,\
        test_case_counter,\
        fromL,\
        toL,\
        actual);\
    return NULL;\
}

single_test(fahrenheit,celsius,convert_fahrenheit_to_celsius)
single_test(celsius,fahrenheit,convert_celsius_to_fahrenheit)
#undef single_test

/**
 * Test cases
 */
#define test_case(f, c) { .fahrenheit = (f), .celsius = (c) },
static temperature_pair test_cases[] = {
    test_case(32, 0)
    test_case(33, 5.0 / 9.0)
    test_case(41, 5.0)
    test_case(23, -5.0)
    test_case(50, 10.0)
    test_case(59, 15.0)
    test_case(95, 35.0)
    test_case(NAN, NAN)
};
#undef test_case

/**
 * Tests
 */
#define test(name,from) char* name(void) {\
    return run_tests(test_cases, single_from_##from);\
}

test(test_convert_celsius_to_fahrenheit, celsius)
test(test_convert_fahrenheit_to_celsius, fahrenheit)
#undef test
