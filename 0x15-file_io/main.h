#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void check_elf_header(unsigned char *e_ident);
void print_elf_magic(unsigned char *e_ident);
void print_elf_class(unsigned char *e_ident);
void print_elf_data_encoding(unsigned char *e_ident);
void print_elf_version(unsigned char *e_ident);
void print_elf_osabi(unsigned char *e_ident);
void print_elf_abi_version(unsigned char *e_ident);
void print_elf_file_type(unsigned int e_type, unsigned char *e_ident);
void print_entry_addr(unsigned long int e_entry, unsigned char *e_ident);
void close_fd_or_exit(int fd);

#endif /* MAIN_H */
