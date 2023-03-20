/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:39:53 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/20 16:10:29 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long int	result;

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
		{
			ft_printf("Error\n");
			exit(0);
		}
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
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
	int	array_seen[stack->len];

	i = 0;
	while (i < stack->len)
	{
		nb = ft_atoi(argv[i + 1]);
		if (check_if_double(nb, array_seen, i) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		array_seen[i] = nb;
		i++;
	}
	return (1);
}