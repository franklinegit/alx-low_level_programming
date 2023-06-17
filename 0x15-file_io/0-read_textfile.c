#include "main.h"

/**
 * read_textfile- function that reads a text file and prints it
 * @filename: text file to read
 * @letters: number of letters
 * Return: actual number of letters read and printed, 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t u, w, t;

	u = open(filename, O_RDONLY);
	if (u == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(u, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(u);
	return (w);
}
