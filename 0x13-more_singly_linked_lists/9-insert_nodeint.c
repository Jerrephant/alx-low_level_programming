#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count;
	listint_t *a;
	listint_t *t = *head;

	a = malloc(sizeof(listint_t));
	if (!a || !head)
		return (NULL);
	a->n = n;
	a->next = NULL;
	if (idx == 0)
	{
		a->next = *head;
		*head = a;
		return (a);
	}

	for (count = 0; t && count < idx; count++)
	{
		if (count == idx - 1)
		{
			a->next = t->next;
			t->next = a;
			return (a);
		}
		else
			t = t->next;
	}

	return (NULL);
}

