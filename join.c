#include "push_swap.h"

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s2 || !(*s2))
		return (NULL);
	str = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = s1[i++];
	str[j++] = ' ';
	i = 0;
	while (s2[i] && s2[i] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	if (s1)
		free (s1);
	return (str);
}