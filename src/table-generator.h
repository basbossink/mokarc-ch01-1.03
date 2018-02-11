typedef double (*converter)(double);
typedef int (*sink)(char const*);

void generate_table(
    double start,
    double maximum,
    double step,
    char const* tabel_header,
    char const* row_format,
    converter conv,
    sink output);
