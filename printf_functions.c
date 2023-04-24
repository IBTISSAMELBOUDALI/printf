#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int arg = va_arg(args, int);

				chars_printed += printf("%d", arg);
			}
			else
			{
				putchar('%');
				putchar(*format);
				chars_printed += 2;
			}
		}
		else
		{
			putchar(*format);
			chars_printed++;
		}

		format++;
	}

	va_end(args);
	return (chars_printed);
}
