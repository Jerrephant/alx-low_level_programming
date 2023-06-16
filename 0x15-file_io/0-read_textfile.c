#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads text file and prints it to the POSIX standard output
 * @filename: filename of the text file to read
 * @letters: the letters to read length
 * Return: num- actual number of letters it could read and print
 *        0 when file cannot open up or read or when filename is NULL
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a;
	ssize_t num;
	char *buffer;
	ssize_t filedesc;

	filedesc = open(filename, O_RDONLY);
	if (filedesc == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	a = read(filedesc, buffer, letters);
	num = write(STDOUT_FILENO, buffer, a);

	free(buffer);
	close(filedesc);
	return (num);
}

