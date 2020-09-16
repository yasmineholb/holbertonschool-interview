#include <stdio.h>
#include "palindrome.h"
/**
 *is_palindrome - function that checks if a given integer is a palindrome
 *@n: integer
 *Return: int
 */
int is_palindrome(unsigned long n)
{
unsigned long i;
unsigned long pal = 0, res;
for (i = n; n != 0; n = n / 10)
{
res = n % 10;
pal = pal * 10 + res;
}
if (i == pal)
return (1);
return (0);
}
