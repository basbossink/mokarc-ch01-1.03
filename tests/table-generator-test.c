#include <math.h>
#include <stdio.h>
#include "../vendor/minunit/minunit.h"
#include "../src/table-generator.h"

static int output_call_count = 0;

double
converter_stub(double input) {
  return input;
}

int
call_counter(const char* line) {
  (void)line;
  return output_call_count++;
}

char *
test_table_generator(void) {
  const double start = 0.0;
  const double maximum = 10.0;
  const double step = 1.0;

  generate_table(start, maximum, step, converter_stub, call_counter);

#define FORMATTED_MESSAGE_SIZE_MAX 1024
  static char message[FORMATTED_MESSAGE_SIZE_MAX];
#undef FORMATTED_MESSAGE_SIZE_MAX
  const int expected = 12;
  const char *message_format = "(%s:%s:%d) expected conversion of table genarator with start %f maximum %f step %f to call output function %d times but it was called %d times.";
  (void)sprintf
    (message,
    message_format,
    __FILE__,
    __func__,
    __LINE__,
    start,
    maximum,
    step,
    expected,
    output_call_count);
  mu_assert(message,
    output_call_count == expected);
  return 0;
}
