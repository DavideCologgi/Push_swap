/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:55:46 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/20 13:08:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *stack)
{
	int	tmp;

	check_last_a(stack);
	tmp = stack->a[stack->last_pos];
	while (stack->last_pos > 0)
	{
		stack->a[stack->last_pos] = stack->a[stack->last_pos - 1];
		stack->last_pos--;
	}
	stack->a[0] = tmp;
}

void	rrb(t_data *stack)
{
	int	tmp;

	check_last_b(stack);
	tmp = stack->b[stack->last_pos];
	while (stack->last_pos > 0)
	{
		stack->b[stack->last_pos] = stack->b[stack->last_pos - 1];
		stack->last_pos--;
	}
	stack->b[0] = tmp;
}

void	rrr(t_data *stack)
{
	rra(stack);
	rrb(stack);
}
