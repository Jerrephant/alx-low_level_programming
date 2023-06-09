#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip to get from one
 * number to another
 * @n: the value of first number
 * @m: the value of second number
 *
 * Return: number of bits a
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count;
	int a = 0;
	unsigned long int number;
	unsigned long int xor = n ^ m;

	for (count = 63; count >= 0; count--)
	{
		number = xor >> count;
		if (number & 1)
			a++;
	}

	return (a);
}

