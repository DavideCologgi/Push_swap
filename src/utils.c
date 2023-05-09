/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:44:27 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/09 11:52:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->b);
	exit (0);
}

void	init(t_data *stack)
{
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = calloc(sizeof(int), stack->len);
	stack->last_a = stack->len - 1;
	stack->last_b = 0;
	stack->move_counter = 0;
}

int	check_sorted_input(t_data *stack)
{
	int	i;

	i = 1;
	while (i < stack->len)
	{
		if (stack->a[i] < stack->a[i - 1])
			return (1);
		i++;
	}
	ft_cleaner(stack);
	return (0);
}
