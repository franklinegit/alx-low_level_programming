#include "main.h"

/**
 * create_file - function that reates a file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write.
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int u, w, count = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}
	u = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(u, text_content, count);
	if (u == -1 || w == -1)
		return (-1);
	close(u);
	return (1);
}
