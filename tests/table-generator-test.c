#include <math.h>
#include "../vendor/minunit/minunit.h"
#include "../src/table-generator.h"

static int output_call_count = 0;

double
converter_stub(double input) {
  return input;
}

int
call_counter(char const * line) {
  (void)line;
  return output_call_count++;
}

char *
test_table_generator(void) {
  const double start = 0.0;
  const double maximum = 10.0;
  const double step = 1.0;

  generate_table(start, maximum, step, "", "", converter_stub, call_counter);

  const int expected = 12;
  char const *message_format = "(%s:%s) expected conversion of table genarator with start %f maximum %f step %f to call output function %d times but it was called %d times.";
  mu_assert(output_call_count == expected,
    message_format,
    __FILE__,
    __func__,
    start,
    maximum,
    step,
    expected,
    output_call_count);
  return 0;
}
