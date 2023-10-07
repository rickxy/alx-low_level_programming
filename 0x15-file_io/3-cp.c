#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_opening_files - open source and destination files
 * @from: pointer to the source file descriptor
 * @to: pointer to the destination file descriptor
 * @argv: array of arguments
 */
 
void handle_opening_files(int *from, int *to, char **argv)
{
	*from = open(argv[1], O_RDONLY);
	if (*from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	*to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		close(*from);
		exit(99);
	}
}

/**
 * handle_reading_writing - read from source and write to destination file
 * @from: source file descriptor
 * @to: destination file descriptor
 * @argv: array of arguments
 */
void handle_reading_writing(int from, int to, char **argv)
{
	int read_count, write_count;
	char buffer[BUFFER_SIZE];

	while ((read_count = read(from, buffer, BUFFER_SIZE)) > 0)
	{
		write_count = write(to, buffer, read_count);
		if (write_count != read_count)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			close(from);
			close(to);
			exit(99);
		}
	}

	if (read_count == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		close(from);
		close(to);
		exit(98);
	}
}

/**
 * close_files - close source and destination files
 * @from: source file descriptor
 * @to: destination file descriptor
 */
void close_files(int from, int to)
{
	if (close(from) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", from);
		exit(100);
	}

	if (close(to) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", to);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: array of arguments
 * Return: 0 on success, or a specific error code on failure
 */
int main(int argc, char *argv[])
{
	int from, to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}

	handle_opening_files(&from, &to, argv);
	handle_reading_writing(from, to, argv);
	close_files(from, to);

	return (0);
}
