/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/20 13:15:34 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_data *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->a[0];
	check_last_a(stack);
	while (i < stack->last_pos)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->last_pos] = tmp;
}

void	rb(t_data *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[0];
	check_last_b(stack);
	while (i < stack->last_pos)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->last_pos] = tmp;
}

void	rr(t_data *stack)
{
	ra(stack);
	rb(stack);
}
