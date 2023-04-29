#include "lists.h"

/**
 * free_listint_safe - Frees a singly linked list
 *in a safe manner to prevent loops.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{

listint_t *current, *tmp;
size_t count = 0;

if (h == NULL)
exit(98);

current = *h;

while (current != NULL)
{
tmp = current;
current = current->next;
free(tmp);

count++;

if (current != NULL && current >= tmp)
{
printf("-> [%p] %d\n", (void *)current, current->n);
free(current);
count++;
break;
}
}

*h = NULL;
return (count);
}
