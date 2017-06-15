#include <stdio.h>
#include "table-generator.h"

#define LINE_LENGTH 1024
static char row[LINE_LENGTH];
#undef LINE_LENGTH

static const char* row_format = "| %14.0f | %11.1f |";
static const char* table_header =
  "| Temperature conversion table |\n"\
  "+------------------------------+\n"\
  "|   Fahrenheit   |   Celsius   |\n"\
  "+----------------+-------------+";

void
generate_table(
  double start,
  double maximum,
  double step,
  converter conv,
  sink output){
  double fahrenheit = start;
  double celsius;
  output(table_header);
  while(fahrenheit <= maximum) {
    celsius = conv(fahrenheit);
    sprintf(row, row_format, fahrenheit, celsius);
    output(row);
    fahrenheit += step;
  }
}
