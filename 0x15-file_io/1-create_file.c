#include "main.h"

/**
 * create_file - Creates a file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: If the function succeeds 1
 *         If the function fails -1
 *         If filename is NULL -1
 *         If text_content is NULL creates an new file
 *
 */
int create_file(const char *filename, char *text_content)
{
	int filedesc, num, leng = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (leng = 0; text_content[leng];)
			leng++;
	}

	filedesc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	num = write(filedesc, text_content, leng);

	if (filedesc == -1 || num == -1)
		return (-1);

	close(filedesc);

	return (1);
}

