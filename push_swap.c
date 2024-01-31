#include "push_swap.h"

void	stackmaker(char **str, int count)
{
	int		i;
	int		numbercount;
	char	*input;
	char	**tarr;

	input = NULL;
	input = joined(input, str, count);
	numbercount = wordcount(input, ' ');
	tarr = ft_split(input, ' ');
	i = 0;
	free(input);
	if (!tarr || tarr[i] == 0 || tarr[i] == NULL)
	{
		freeer (tarr, i);
		exit (printf("bad\n"));
	}
	if (parser(tarr, numbercount) == 0)
		printf("good");
	else
		exit(printf("bad\n"));
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit (printf("bad\n"));
	stackmaker(av, ac - 1);
	return (0);
}