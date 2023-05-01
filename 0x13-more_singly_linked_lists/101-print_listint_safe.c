#include "lists.h"

/**
 * looped_listint - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count = 1;

if (head == NULL || head->next == NULL)
return (0);

slow = head->next;
fast = (head->next)->next;

while (fast)
{
if (slow == fast)
{
slow = head;

do {
count++;
slow = slow->next;
fast = fast->next;
} while (slow != fast);

slow = slow->next;
while (slow != fast)
{
count++;
slow = slow->next;
}

return (count);
}

slow = slow->next;
fast = (fast->next)->next;
}

return (0);
}

/**
 * print_listint_safe - Prints a singly linked
 *list in a safe manner to prevent loops.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{

size_t slow, count = 0;
slow = looped_listint(head);

if (slow == 0)
{
for (; head != NULL; slow++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (count = 0; count < slow; count++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (slow);
}
