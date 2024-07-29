#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - Handles the 'c' format specifier
 * @args: The argument list
 * Return: The number of characters printed
 */
int handle_char(va_list args)
{
	char c = (char) va_arg(args, int); /* Cast int to char */

	write(1, &c, 1);
	return (1);
}

/**
 * handle_string - Handles the 's' format specifier
 * @args: The argument list
 * Return: The number of characters printed
 */
int handle_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

/**
 * handle_percent - Handles the '%' format specifier
 * Return: The number of characters printed
 */
int handle_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += handle_char(args);
					break;
				case 's':
					count += handle_string(args);
					break;
				case '%':
					count += handle_percent();
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
