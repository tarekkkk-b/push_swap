#include "push_swap.h"

int	hmm(char *str, int	*arr)
{
	int	j;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (free(arr), 1);
	while (str[j])
	{
		if (ft_isdigit(str[j]) == 0)
			return (free(arr), 1);
		else
			j++;
	}
	return (0);
}

int	hmm2(int *intarr, char **str, int i)
{
	if (i == 0)
		intarr[i] = t_atoi(str[i]);
	else
	{
		if (checker(&intarr, t_atoi(str[i]), i) == 0)
			intarr[i] = t_atoi(str[i]);
		else
			return (1);
	}
	return (0);
}

int	parser(char **arr, int count)
{
	int	i;
	int	*intarr;
	int error;

	i = 0;
	error = 0;
	intarr = malloc(sizeof(int) * count);
	if (!intarr)
		return (1);
	while (i < count)
	{
		if (hmm(arr[i], intarr) == 0)
		{
			if (hmm2(intarr, arr, i) == 1)
				error = 1;
		}
		else
			error = 1;
		i++;
	}
	freeer (arr, i);
	// if (error == 1)
	// if (intarr)
	// 	free (intarr);
	return (error);
}
