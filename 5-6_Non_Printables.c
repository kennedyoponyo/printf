#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 *
 * Return: Int(number of characters printed.
 *
 */int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_c = 0, padding = ' ';
	int index = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padding, extra_c, padding_start));
}


/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 *
 * Return: Int(number of characters printed
 *
 */int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
