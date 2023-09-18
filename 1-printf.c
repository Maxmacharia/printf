#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: Format
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (f
