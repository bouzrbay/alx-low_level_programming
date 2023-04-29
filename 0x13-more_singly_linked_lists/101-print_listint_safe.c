#include "lists.h"

/**
 * print_listint_safe - Prints a singly linked list in a safe manner to prevent loops.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{

const listint_t *slow, *fast;
size_t count = 0;

if (head == NULL)
exit(98);

slow = head;
fast = head->next;

while (fast != NULL && fast < slow)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next;

count++;
}

printf("[%p] %d\n", (void *)slow, slow->n);
count++;

if (fast != NULL)
{
printf("-> [%p] %d\n", (void *)fast, fast->n);
count++;
}

return (count);
}
