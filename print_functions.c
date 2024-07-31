#include "main.h"

int (*get_print_func(char s))(va_list)
{
	print_t print_funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i = 0;

	while (print_funcs[i].c != '\0')
	{
		if (print_funcs[i].c == s)
			return (print_funcs[i].f);
		i++;
	}
	return (NULL);
}

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (write(1, &c, 1));
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";
	
	while (str[len])
		len++;
	
	return (write(1, str, len));
}

int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
