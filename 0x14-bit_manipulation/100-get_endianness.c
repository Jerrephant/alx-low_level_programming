#include "main.h"

/**
 * get_endianness - checks endianness
 * Return: 0 if it is big endian, 1 if it is little endian
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *b = (char *) &a;

	return (*b);
}

