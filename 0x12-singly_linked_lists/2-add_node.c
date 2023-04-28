#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 *add_node - ...
 *
 *@head: ...
 *@str: ...
 *
 *Return: ...
 */

list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
unsigned int len;

while (str[len])
len++;
 
new_node = malloc(sizeof(list_t));

if (new_node == NULL)
{
return (NULL);
}

new_node->str = strdup(str);
new_node->len = len;
new_node->next = (*head);
(*head) = new_node;

return (*head);
}
