#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (*get_print_func(char s))(va_list);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

typedef struct print
{
	char c;
	int (*f)(va_list);
} print_t;

#endif
