#include "main.h"

/**
 *_sqrt_recursion -  function that returns the natural
 *square root of a number.
 *
 *@n: input
 *
 *Return: If n does not have a natural square root,
 *the function should return -1
 */


int _sqrt_recursion(int n)
{
int sqrt_n = _sqrt_recursion(n / 2);
if (n < 0)
{
return (-1);
/*negative numbers don't have a natural square root*/
}
if (n == 0 || n == 1)
{
return (n);
/*base case, the square root of 0 and 1 is itself*/
}
/*recursively calculate the square root of n/2*/

/*if the square root of n/2 is -1, then n doesn't have a natural square root*/
if (sqrt_n == -1)
{
return (-1);
}
/*check if sqrt_n is actually the square root of n*/
if (sqrt_n * sqrt_n == n)
{
return (sqrt_n);
}
else if ((sqrt_n + 1) * (sqrt_n + 1) == n)
{
return (sqrt_n + 1);
}
else
{
return (-1);
}
}
