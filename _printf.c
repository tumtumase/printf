#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*print_func)(va_list);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			
			print_func = get_print_func(format[i]);
			if (print_func)
				count += print_func(args);
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (count);
}
