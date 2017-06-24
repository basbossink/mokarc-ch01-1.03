#include <stdio.h>
#include "table-generator.h"

#define LINE_LENGTH 1024
static char row[LINE_LENGTH];
#undef LINE_LENGTH

void
generate_table(
  double start,
  double maximum,
  double step,
  const char* table_header,
  const char* row_format,
  converter conv,
  sink output){
  double fahrenheit = start;
  double celsius;
  output(table_header);
  while(fahrenheit <= maximum) {
    celsius = conv(fahrenheit);
    snprintf(row, sizeof row, row_format, fahrenheit, celsius);
    output(row);
    fahrenheit += step;
  }
}
