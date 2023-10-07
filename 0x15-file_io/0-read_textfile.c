#include "main.h"

/**
 * read_textfile - Reads a text file and prints to the POSIX stdout.
 * @filename: Pointer to the name of the file.
 * @letters: Number of letters it should read and print.
 *
 * Return: Actual number of letters it could read and print,
 *		 or 0 if the file cannot be opened, read,
 *		 filename is NULL, or write fails or does not write
 *		 the expected amount of bytes.
 */
 
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	nrd = read(fd, buffer, letters);
	if (nrd == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	nwr = write(STDOUT_FILENO, buffer, nrd);
	if (nwr == -1 || nwr != nrd)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (nwr);
}
