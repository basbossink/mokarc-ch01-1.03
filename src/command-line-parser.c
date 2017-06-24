#include <stdio.h>
#include <string.h>

#include "command-line-parser.h"


#define MAX_ERROR_SIZE 1024
static char error_message_buffer[MAX_ERROR_SIZE];
#undef MAX_ERROR_SIZE


struct option_flags
parse_command_line(
  int argc,
  char* const *argv,
  getopt_long_fn getopt_fn,
  error_callback error_occurred) {
  struct option_flags parsed = {
    .show_celsius_table = false,
    .show_fahrenheit_table = false
  };
  int getopt_value = 0;
  static struct option long_options[] = {
    { "celsius", no_argument, NULL, 'c'},
    { "fahrenheit", no_argument, NULL, 'f' },
    { NULL, 0, NULL, 0 }
  };
  if(argc > 3) {
    snprintf(
      error_message_buffer,
      sizeof error_message_buffer,
      "To many arguments '%d', expected no more than 2 arguments.",
      argc);
      error_occurred(error_message_buffer);
  } else {
    int option_index = 0;
    int arguments_index = 1;
    while ((getopt_value = getopt_fn(argc, argv, "cf", long_options, &option_index)) != -1) {
      switch(getopt_value) {
      case 'c':
        parsed.show_celsius_table = true;
        break;
      case 'f':
        parsed.show_fahrenheit_table = true;
        break;
      default:
        error_occurred("");
        break;
      }
      arguments_index++;
    }
    if(!parsed.show_celsius_table && !parsed.show_fahrenheit_table) {
      parsed.show_fahrenheit_table = true;
    }
  }
  return parsed;
}

