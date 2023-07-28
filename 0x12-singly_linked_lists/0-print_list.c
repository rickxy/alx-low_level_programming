#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the start of the list
 * Return: number of nodes in the list
 **/
size_t print_list(const list_t *h)
{
	const list_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		printf("[%u] %s\n", current->len, current->str ? current->str : "(nil)");
		current = current->next;
		n++;
	}

	return (n);
}
