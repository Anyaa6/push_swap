#include "push_swap.h"

int	is_int(char *argv)
{	
	int			y;

	y = 0;
	if (argv[y] == '-' && ft_isdigit(argv[y + 1]))
		y++;
	else if (argv[y] == '-' && !ft_isdigit(argv[y + 1]))
		return (0);
	while (argv[y] && ft_isdigit(argv[y]))
		y++;
	if (argv[y] && ft_isdigit(argv[y]) == 0)
		return (0);
	return (1);
}

int	duplicate_not_int(char **argv, int i)
{
	int			y;

	while (argv[i] != NULL)
	{
		if (is_int(argv[i]) == 0)
			return (1);
		y = 1;
		while (argv[i + y] != NULL)
		{
			if ((ft_strlen(argv[i]) != ft_strlen(argv[i + y])) \
			|| (ft_strncmp(argv[i], argv[i + y], ft_strlen(argv[i]))))
				y++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	formatted_arg(t_data *d, char ***argv, int argc)
{
	int			i;

	if (argc == 2)
	{
		i = 0;
		*argv = ft_split((*argv)[1], ' ');
		while ((*argv)[i] != NULL)
			i++;
		d->nb_arg = i;
		d->nb_in_a = d->nb_arg;
		return (0);
	}
	return (1);
}

void	check_arg(t_data *d, char **argv, int argc)
{
	int			i;
	long		content;

	i = formatted_arg(d, &argv, argc);
	if (duplicate_not_int(argv, i) == 1)
		error(d, 1);
	while (argv[i] != NULL)
	{
		content = ft_atoi(argv[i]);
		if (content < -2147483648 || content > 2147483647)
			error(d, 2);
		lstadd(&(d->a), newnode(content));
		i++;
	}
	if (argc == 2)
		free_split(argv);
}
