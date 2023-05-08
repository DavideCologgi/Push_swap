/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:18:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/08 13:58:06 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_max(t_data *stack)
{
	int	i;

	i = 0;
	stack->max_pos = 0;
	stack->max = stack->b[0];
	while (i < stack->last_b)
	{
		if (stack->max < stack->b[i])
		{
			stack->max = stack->b[i];
			stack->max_pos = i;
		}
		i++;
	}
}

void	get_min(t_data *stack)
{
	int	i;

	i = 0;
	stack->min_pos = 0;
	stack->min = stack->b[0];
	while (i < stack->last_b)
	{
		if (stack->min > stack->b[i])
		{
			stack->min = stack->b[i];
			stack->min_pos = i;
		}
		i++;
	}
}

void	nb_is_between(t_data *stack, int nb)
{
	int	i;
	int	x;
	int	min_diff;

	i = 0;
	x = 0;
	stack->b_pos = stack->min_pos;
	min_diff = nb - stack->min;
	while (i < stack->last_b)
	{
		x = nb - stack->b[i];
		if (x > 0 && x < min_diff)
		{
			stack->b_pos = i;
			min_diff = x;
		}
		i++;
	}
}

void	assign_best_nb(t_data *stack, int a, int b, int i)
{
	stack->a_moves = a;
	stack->b_moves = b;
	stack->best_moves = stack->tot_moves;
	stack->best_pos_a = stack->a_pos;
	stack->best_pos_b = stack->b_pos;
	stack->best_nb = stack->a[i];
}
