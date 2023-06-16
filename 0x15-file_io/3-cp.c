#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *new_buffer(char *filename);
void close_file(int filedesc);

/**
 * new_buffer - a buffer that has 1024 bytes at a time to read
 * @filename: the name of the file
 * Return: the new allocated buffer
 *
 */
char *new_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s", filename);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors
 * @filedesc: The file descriptor to close
 *
 */
void close_file(int filedesc)
{
	int a;

	a = close(filedesc);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", filedesc);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments to the program
 * @argv: array of pointers to the arguments
 * Message_code: If the number of argument is not correct - exit with code 97
 *      If file_from does not exist or you cannot read it - exit with code 98
 *      If file_to cannot be created or written to - exit with code 99
 *      If file_to or file_from cannot be closed - exit with code 100
 * Return: 0 when program succeeds
 *
 */
int main(int argc, char *argv[])
{
	int a, b, to, from;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = new_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		b = write(to, buffer, a);
		if (to == -1 || b == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		a = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

