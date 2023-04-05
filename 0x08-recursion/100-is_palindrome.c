#include "main.h"

/**
 *is_palindrome - function that returns 1 if a string
 *is a palindrome and 0 if not
 *
 *@s: input string
 *
 *Return: 1 if a string is a palindrome and 0 if not
 *
 */

#include <string.h>

int is_palindrome(char *s)
{

int len = strlen(s);
int i;

for (i = 0; i < len / 2; i++)
{
if (s[i] != s[len - i - 1])
{
return (0);
}
}
return (1);
}
