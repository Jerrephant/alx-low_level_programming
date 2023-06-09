#include "main.h"

/**
 * binary_to_uint - should convert binary number to unsigned int
 * @b: string with the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int count;
	unsigned int decimal = 0;

	if (!b)
		return (0);

	for (count = 0; b[count]; count++)
	{
		if (b[count] < '0' || b[count] > '1')
			return (0);
		decimal = 2 * decimal + (b[count] - '0');
	}

	return (decimal);
}

