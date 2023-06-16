#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: -1 on function failure or filename is NULL or file does not exist
 *         1 on function success or if file exists
 *
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, num, leng = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (leng = 0; text_content[leng];)
			leng++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	num = write(a, text_content, leng);

	if (a == -1 || num == -1)
		return (-1);

	close(a);

	return (1);
}

