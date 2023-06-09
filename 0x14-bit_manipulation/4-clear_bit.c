#include "main.h"

/**
 * clear_bit - sets the bit value at a given index to 0
 * @n: number to change
 * @index: index of the bit to set starting from 0
 *
 * Return: 1 if it worked, -1 if it failed
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

