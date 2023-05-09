/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:22:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/09 15:05:17 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	control_doubles(t_data *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->a[i] == stack->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	control_fill_stack(t_data *stack, char **temp)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < stack->len)
	{
		if (is_valid(temp[i]) == 1)
		{
			y = ft_atoi(temp[i]);
			if ((y >= -2147483648) && (y <= 2147483647))
				stack->a[i] = y;
			else
				print_error();
		}
		else
		{
			free(temp);
			print_error();
		}
		i++;
	}
	if (control_doubles(stack) == 0)
		print_error();
}

int	is_valid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	string_input(t_data *stack, char *argv)
{
	char	**tmp;

	tmp = ft_split(argv, ' ');
	stack->len = count_val(tmp);
	init(stack);
	control_fill_stack(stack, tmp);
}
