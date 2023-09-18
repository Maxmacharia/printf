#include "main.h"

/**
 * it_to_str - integer conversion
 * @num: number
 * Return: character
 */

char *it_to_str(int num)
{
	static char buffer[20];
	int i = 0;
	int is_negative = 0;

	/* Handle negative numbers */
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	/* Special case for 0 */
	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
		{
		/* Convert the number to a string without reversing */
		while (num > 0)
		{
			buffer[i++] = num % 10 + '0';
			num /= 10;
		}
	}

	/* Add the negative sign if needed */
	if (is_negative)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0'; /* Null-terminate the string */
	return (buffer);
}

/**
 * _printf - Function that produces output according to format
 * @format: Format
 * Return: Number of chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list list;

	if (format == NULL || *format == '\0')
		return (-1);

	va_start(list, format);

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
			if (*format == 'b')
			{
				int b = va_arg(list, int);
				char *binaryStr = it_to_str(b);
				int str_len = 0;

				while (binaryStr[str_len] != '\0')
				{
					str_len++;
				}
				write(1, binaryStr, str_len);
				count += str_len;
			}
		}
		format++;
	}
	va_end(list);
	return (count);
}
