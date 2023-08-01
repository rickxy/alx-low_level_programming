#include "lists.h"

/**
 * sum_listint - returns the sum of all the data in a list
 * @head: pointer to the head of the list
 *
 * Return: if list is empty, return 0; else, return sum of the data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current;

	for (current = head; current; current = current->next)
		sum += current->n;

	return (sum);
}
