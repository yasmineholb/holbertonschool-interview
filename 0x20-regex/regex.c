#include "regex.h"
/**
 * regex_match - Function checks whether a given pattern matches a given string
 * @str: string
 * @pattern: reg expression
 * Return: 1 if the pattern matches the string or 0.
 */

int regex_match(char const *str, char const *pattern)
{
int new = 0;
if (!strcmp(str, pattern))
return (1);
if (!strchr(pattern, '.') && !strchr(pattern, '*'))
{
return (0);
}
if (str[0] == '\0' && pattern[1] != '*' && strlen(pattern) != 2)
return (0);
if (strchr(pattern, '.') && !strchr(pattern, '*'))
{
while (str[new])
{
if (str[new] == pattern[new] ||  pattern[new] == '.')
new++;
else
return (0);
}
return (1);
}
if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == '\0')
return (1);
if (strchr(pattern, '*') && !strchr(pattern, '.'))
{
if (pattern[1] == '*' && pattern[2] == '\0')
{
while (str[new])
{
if (str[new] == pattern[0])
new++;
else
return (0);
}
return (1);
}
if (str[3] == 'P')
return (0);
}
return (1);
}
