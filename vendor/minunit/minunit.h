/*
 * Adapted from: http://www.jera.com/techinfo/jtns/jtn002.html
 */
#include<stdio.h>

#define mu_assert(test, ...) do { if (!(test)) { char *msg; asprintf(&msg, __VA_ARGS__); return msg;} } while (0)
#define mu_run_test(test) do { printf(#test " : "); char *message = test(); tests_run++; \
    if (message) { return message;} else { printf("OK\n");} } while (0)
extern int tests_run;
