#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    curr_i++;
    if (format[curr_i] == '-')
    {
        precision = -1;
        curr_i++;
    }

    for (; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    if (precision < -1)
        precision = -1;

    if (precision == -1 && (format[curr_i] == 'f' || format[curr_i] == 'e' ||
                            format[curr_i] == 'E' || format[curr_i] == 'g' ||
                            format[curr_i] == 'G'))
        precision = 6;

    if (format[curr_i] != 'd' && format[curr_i] != 'i' && format[curr_i] != 'o' &&
        format[curr_i] != 'u' && format[curr_i] != 'x' && format[curr_i] != 'X' &&
        format[curr_i] != 'f' && format[curr_i] != 'e' && format[curr_i] != 'E' &&
        format[curr_i] != 'g' && format[curr_i] != 'G' && format[curr_i] != 's')
        precision = -1;

    *i = curr_i - 1;

    return (precision);
}
