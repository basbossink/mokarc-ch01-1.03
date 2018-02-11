#include <stdio.h>
#include <stdlib.h>
#include "table-generator.h"

void generate_table(
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
        char* row;
        asprintf(&row, row_format, fahrenheit, celsius);
        output(row);
        free(row);
        fahrenheit += step;
    }
}
