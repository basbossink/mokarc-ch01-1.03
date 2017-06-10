typedef double (*converter)(double);
typedef void (*sink)(double, double);

void
generate_table(
  double start,
  double maximum,
  double step,
  converter conv,
  sink output);
