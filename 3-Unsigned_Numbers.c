#include "main.h"

/*
 * print_unsigned - Prints an unsigned number
 *
 * Return: Int(number of characters printed.)
 */int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsigned(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}



/*
 * print_octal - Prints an unsigned number in octal notation
 *
 * Return: Int(number of characters printed)
 */int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial = number;

	UNUSED(width);

	number = convert_size_unsigned(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && initial != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/*
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 *
 * Return: Int(number of characters printed)
 */int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_upper_or_lower_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*
 * print_upper_hexa - Prints an unsigned number in upper hexadecimal notation
 *
 * Return: Int(number of characters printed)
 */int print_upper_hexa(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_upper_or_lower_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*
 * print_upper_or_lower_hexa - Prints a hexadecimal number in lower or upper
 *
 * Return: Int(number of characters printed)
 */int print_upper_or_lower_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial = number;

	UNUSED(width);

	number = convert_size_unsigned(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && initial != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}
