#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
mk_buffer binary_fmt(mk_buffer buffer, va_list args);
char *it_to_str(int num);

#endif
