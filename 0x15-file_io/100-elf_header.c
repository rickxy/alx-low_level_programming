#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include "main.h"

/**
 * check_elf_header - checks if the file is an ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: If the file is not an ELF file, the function prints an error
 * and exits.
 */
void check_elf_header(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_elf_magic - prints the magic number of the ELF header.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: Prints the magic number in hexadecimal format.
 */
void print_elf_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * print_elf_class - prints the class of the ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: Indicates if the file is ELF32 or ELF64 or unknown.
 */
void print_elf_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_elf_data_encoding - prints data encoding of the ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: Indicates if the file is little or big endian or unknown.
 */
void print_elf_data_encoding(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_elf_version - prints the version info of the ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: If the version is current, "current" is printed next to the
 * version number. For other versions, only the number is printed.
 */
void print_elf_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_elf_osabi - prints the OS/ABI of the ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: It checks the OS/ABI and prints its corresponding name.
 */
void print_elf_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_elf_abi_version - prints the ABI version of ELF.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: Prints the ABI version number.
 */
void print_elf_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_elf_file_type - prints the type of the ELF file.
 * @e_type: type of ELF file.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: It checks the file type (Relocatable, Executable, etc.)
 * and prints its corresponding description.
 */
void print_elf_file_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry_addr - prints the entry point address of the ELF file.
 * @e_entry: entry point address.
 * @e_ident: pointer to the identifier of the ELF header.
 *
 * Description: Converts and prints the entry point depending on data encoding.
 */
void print_entry_addr(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx\n", e_entry);
	}
}

/**
 * close_fd_or_exit - closes the ELF file.
 * @fd: file descriptor of the ELF file.
 *
 * Description: Closes the given file descriptor. If it fails, prints an error
 * and exits.
 */
void close_fd_or_exit(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * main - Entry point to the ELF file reader.
 * @argc: Argument count. Unused in this function but kept for compatibility.
 * @argv: Argument vector; expects the ELF file path as the second element.
 *
 * Description: Opens the provided ELF file, reads its header, and then
 * prints relevant data. On error, it outputs an error message to the
 * standard error and exits with a status of 98.
 *
 * Return: 0 on success, exits with a status of 98 on error.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd;
	ssize_t bytesRead;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_fd_or_exit(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bytesRead = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		free(header);
		close_fd_or_exit(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf_header(header->e_ident);
	printf("ELF Header:\n");
	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident);
	print_elf_data_encoding(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_abi_version(header->e_ident);
	print_elf_file_type(header->e_type, header->e_ident);
	print_entry_addr(header->e_entry, header->e_ident);

	free(header);
	close_fd_or_exit(fd);
	return (0);
}
