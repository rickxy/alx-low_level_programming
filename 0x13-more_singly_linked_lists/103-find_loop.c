#include "lists.h"

/**
 * find_listint_loop - finds the loop in a listint_t linked list.
 * @head: pointer to the 1st node of the linked list
 *
 * Return: Address of the node where the loop starts,
 * or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr = head;
	listint_t *fast_ptr = head;

	if (!head)
		return (NULL);

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		if (fast_ptr == slow_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			return (fast_ptr);
		}
	}

	return (NULL);
}
