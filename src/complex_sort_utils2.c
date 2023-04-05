/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:18:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/05 15:16:31 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_data *stack)
{
	int	i;
	int	max;

	i = 0;
	stack->max = 0;
	max = stack->b[0];
	while (i < stack->last_b)
	{
		i++;
		if (max < stack->b[i])
		{
			max = stack->b[i];
			stack->max_pos = i;
		}
	}
	return (max);
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
