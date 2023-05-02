/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:18:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 11:42:44 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_max(t_data *stack)
{
	int	i;

	i = 0;
	stack->max = 0;
	stack->max = stack->b[0];
	while (i < stack->last_b)
	{
		i++;
		if (stack->max < stack->b[i])
		{
			stack->max = stack->b[i];
			stack->max_pos = i;
		}
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
