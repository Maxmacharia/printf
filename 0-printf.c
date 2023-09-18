#include "main.h"

/**
 * _printf - Function that produces output according to a format
 * @format: Format
 * Return: Number of chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list list_of_args;

	if (format == NULL)
		return (-1);

	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str =  va_arg(list_of_args, char*);
				int str_len = 0;

				while ((str[str_len]) != '\0')
					str_len++;
				write(1, str, str_len);
				count += str_len;
			}
		} format++;
	} va_end(list_of_args);
	return (0);
}
