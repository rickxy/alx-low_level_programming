#include "main.h"

/**
 * create_file - creates a file and writes content into it.
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
 
int create_file(const char *filename, char *text_content)
{
	int fd, write_res;
	ssize_t len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		write_res = write(fd, text_content, len);
		if (write_res == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
