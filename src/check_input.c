/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:39:53 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/04 11:49:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
			print_error();
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		print_error();
	return (result * sign);
}

int	check_if_double(int nb, int	*array, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (array[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(t_data *stack, char **argv)
{
	int	i;
	int	nb;
	int	*array_seen;

	i = 0;
	array_seen = calloc(sizeof(int), stack->len);
	while (i < stack->len)
	{
		nb = ft_atoi(argv[i + 1]);
		if (check_if_double(nb, array_seen, i) == 0)
			print_error();
		array_seen[i] = nb;
		i++;
	}
	free (array_seen);
	return (1);
}
