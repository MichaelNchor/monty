#include "monty.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: tr compared.
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals otherwise another
 * value if different.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @s: string to review.
 * @c: charind
 * Return: 1 if successful,otherwise 0.
 */
int _sch(char *s, char c)
{
	int current = 0;

	while (s[current] != '\0')
	{
		if (s[current] == c)
		{
			break;
		}
		current++;
	}
	if (s[current] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - functiing into tokens depending of the delimit
 * @s: string to cut in parts.
 * @d: delimiters
 *
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
