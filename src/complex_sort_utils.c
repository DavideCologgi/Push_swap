/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 12:31:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr_move(t_data *stack) //
{
	int	n_rot;

	if (stack->a_moves >= stack->b_moves)
	{
		n_rot = stack->b_moves;
		while (stack->b_moves-- > 0)
			rrr(stack);
		while (n_rot++ != stack->a_moves)
			rra(stack, 0);
	}
	else
	{
		n_rot = stack->a_moves;
		while (stack->a_moves-- > 0)
			rrr(stack);
		while (n_rot++ != stack->b_moves)
			rrb(stack, 0);
	}
}

void	rr_move(t_data *stack) //
{
	int	n_rot;

	if (stack->a_moves >= stack->b_moves)
	{
		n_rot = stack->b_moves;
		while (stack->b_moves-- > 0)
			rr(stack);
		while (n_rot++ != stack->a_moves)
			ra(stack, 0);
	}
	else
	{
		n_rot = stack->a_moves;
		while (stack->a_moves-- > 0)
			rr(stack);
		while (n_rot++ != stack->b_moves)
			rb(stack, 0);
	}
}

void	rra_rb_move(t_data *stack)
{
	while (stack->a_moves-- > 0)
		rra(stack, 0);
	while (stack->b_moves-- > 0)
		rb(stack, 0);
}

void	ra_rrb_move(t_data *stack)
{
	while (stack->a_moves-- > 0)
		ra(stack, 0);
	while (stack->b_moves-- > 0)
		rrb(stack, 0);
}
