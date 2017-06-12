#include "table-generator.h"

void
generate_table(
  double start,
  double maximum,
  double step,
  converter conv,
  sink output){
  double fahrenheit = start;
  double celsius;
  while(fahrenheit <= maximum) {
    celsius = conv(fahrenheit);
    struct temperature_pair pair = {
      .fahrenheit = fahrenheit,
      .celsius = celsius
    };
    output(pair);
    fahrenheit += step;
  }
}
