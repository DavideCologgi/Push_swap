/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:45:46 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/29 14:27:09 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min(t_data *stack)
{
	int	i;

	i = 1;
	stack->min = stack->a[0];
	while (i <= stack->last_a)
	{
		if (stack->a[i] < stack->min)
			stack->min = stack->a[i];
		i++;
	}
}

void	find_max(t_data *stack)
{
	int	i;

	i = 1;
	stack->max = stack->a[0];
	while (i <= stack->last_a)
	{
		if (stack->a[i] > stack->max)
			stack->max = stack->a[i];
		i++;
	}
}
