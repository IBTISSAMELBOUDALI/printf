#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				int j;

				if (s == NULL)
					s = "(null)";
				for (j = 0; s[j]; j++)
				{
					write(1, &s[j], 1);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
		}
	}

	va_end(args);

	return (count);
}
