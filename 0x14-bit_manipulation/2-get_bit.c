#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to look for
 * @index: index start from 0 of the bit to get
 *
 * Return: value of the bit at index or -1 if failed
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}

