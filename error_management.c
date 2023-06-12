
#include "push_swap.h"

void	check_input_is_only_program_name(int argc)
{
	if (argc == 1)
		exit(1);
}

void	check_input_numbers_are_not_duplicated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_input_numbers_are_integers(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && j == 0)
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_input_numbers_are_not_overflow(int argc, char *argv[])
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_convert_to_int(argv[i]);
		if (num > 2147483647)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	check_input_numbers_are_not_underflow(int argc, char *argv[])
{
	int			i;
	long long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_convert_to_int(argv[i]);
		if (num < -2147483648)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}
