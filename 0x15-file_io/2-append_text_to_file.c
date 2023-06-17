#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: pointer to the name of the file.
 * @text_content: string to add
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int u, w, count = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}
	u = open(filename, O_WRONLY | O_APPEND);
	w = write(u, text_content, count);
	if (u == -1 || w == -1)
		return (-1);
	close(u);
	return (1);
}
