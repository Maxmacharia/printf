#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Format.
 * @i: argument.
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int current;
	int width = 0;

	current = *i + 1;
	while (format[current] != '\0')
	{
		if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
		current++;
	}
	*i = current - 1;
	return (width);
}
