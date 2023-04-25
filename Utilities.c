#include "main.h"

/**
 * is_printable - Evaluates if a character is printable
 *
 * Return: 1 if c is printable, 0 otherwise
 *
 */int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}


/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * 
 * Return: Always 3
 *
 */int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}


/**
 * is_digit - Verifies if a char is a digit
 *
 * Return: 1 if c is a digit, 0 otherwise
 *
 */int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}


/**
 * convert_size_number - Casts a number to the specified size
 * 
 * Return: Casted value of number
 *
 */long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}


/**
 * convert_size_unsigned - Casts a number to the specified size
 * 
 * Return: Casted value of number
 *
 */long int convert_size_unsigned(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);
	return ((unsigned int)number);
}
