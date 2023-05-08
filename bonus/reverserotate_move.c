/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:55:46 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 10:27:08 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->a[stack->last_a];
	while (i < stack->last_a)
	{
		stack->a[stack->last_a - i] = stack->a[stack->last_a - i - 1];
		i++;
	}
	stack->a[0] = tmp;
	if (flag == 0)
	{
		ft_printf("rra\n");
		stack->move_counter++;
	}
}

void	rrb(t_data *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->b[stack->last_b - 1];
	while (i < stack->last_b)
	{
		stack->b[stack->last_b - i] = stack->b[stack->last_b - i - 1];
		i++;
	}
	stack->b[0] = tmp;
	if (flag == 0)
	{
		ft_printf("rrb\n");
		stack->move_counter++;
	}
}

void	rrr(t_data *stack, int flag)
{
	rra(stack, 1);
	rrb(stack, 1);
	if (flag == 0)
		ft_printf("rrr\n");
	stack->move_counter++;
}
