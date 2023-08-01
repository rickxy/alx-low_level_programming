#include "lists.h"

/**
 * free_listint_safe - Safely frees a list of integers.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0;
	int diff;
	listint_t *temp_node;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;

		if (diff > 0)
		{
			temp_node = (*h)->next;
			free(*h);
			*h = temp_node;
			node_count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			node_count++;
			break;
		}
	}

	*h = NULL;

	return (node_count);
}
