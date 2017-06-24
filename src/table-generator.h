struct temperature_pair {
  double fahrenheit;
  double celsius;
};

typedef double (*converter)(double);
typedef int (*sink)(const char*);

void
generate_table(
  double start,
  double maximum,
  double step,
  const char* tabel_header,
  const char* row_format,
  converter conv,
  sink output);
