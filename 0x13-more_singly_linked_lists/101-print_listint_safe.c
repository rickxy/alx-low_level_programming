#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * listint_t_reallocate - Reallocates memory for an array of pointers to nodes
 *				in a linked list.
 * @list: Pointer to the old list to append.
 * @size: Size of the new list (always one more than the old list).
 * @new_node: Pointer to the new node to add to the list.
 *
 * Return: Pointer to the new list.
 */
const listint_t **listint_t_reallocate(const listint_t **list, size_t size,
					const listint_t *new_node)
{
	const listint_t **new_list;
	size_t index;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free(list);
		exit(98);
	}

	for (index = 0; index < size - 1; index++)
		new_list[index] = list[index];
	new_list[index] = new_node;
	free(list);

	return (new_list);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely (detects loops).
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t index, node_count = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (index = 0; index < node_count; index++)
		{
			if (head == list[index])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (node_count);
			}
		}

		node_count++;
		list = listint_t_reallocate(list, node_count, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	free(list);
	return (node_count);
}
