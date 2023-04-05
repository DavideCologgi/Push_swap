/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/05 15:10:50 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr_move(t_data *stack) //
{
	int	a_rot;
	int	b_rot;
	int	n_rot;
	int	max_b;

	max_b = get_max(stack);
	get_min(stack);
	a_rot = stack->last_a - stack->best_pos_a + 1;
	if (stack->best_nb > max_b || stack->best_nb < stack->min)
		b_rot = stack->last_b - stack->best_pos_b - 1;
	else
		b_rot = stack->last_b - stack->best_pos_b;
	if (a_rot >= b_rot)
	{
		n_rot = b_rot;
		while (b_rot-- > 0)
			rrr(stack);
		while (n_rot++ != a_rot)
			rra(stack, 0);
	}
	else
	{
		n_rot = a_rot;
		while (a_rot-- > 0)
			rrr(stack);
		while (n_rot++ != b_rot)
			rrb(stack, 0);
	}
}

void	rr_move(t_data *stack) //
{
	int	a_rot;
	int	b_rot;
	int	n_rot;
	int	max_b;

	max_b = get_max(stack);
	a_rot = stack->best_pos_a;
	if (stack->best_nb > max_b || stack->best_nb < stack->min)
		b_rot = stack->best_pos_b;
	else
		b_rot = stack->best_pos_b;
	if (a_rot >= b_rot)
	{
		n_rot = b_rot;
		while (b_rot-- > 0)
			rr(stack);
		while (n_rot++ != a_rot)
			ra(stack, 0);
	}
	else
	{
		n_rot = a_rot;
		while (a_rot-- > 0)
			rr(stack);
		while (n_rot++ != b_rot)
			rb(stack, 0);
	}
}

void	rra_rb_move(t_data *stack)
{
	int	a_rot;
	int	b_rot;
	int	max_b;

	max_b = get_max(stack);
	a_rot = stack->last_a - stack->best_pos_a + 1;
	if (stack->best_nb > max_b || stack->best_nb < stack->min)
		b_rot = stack->best_pos_b;
	else
		b_rot = stack->best_pos_b + 1;
	while (a_rot-- > 0)
		rra(stack, 0);
	while (b_rot-- > 0)
		rb(stack, 0);
}

void	ra_rrb_move(t_data *stack)
{
	int	a_rot;
	int	b_rot;
	int	max_b;

	max_b = get_max(stack);
	a_rot = stack->best_pos_a;
	if (stack->best_nb > max_b || stack->best_nb < stack->min)
		b_rot = stack->last_b - stack->best_pos_b - 1;
	else
		b_rot = stack->last_b - stack->best_pos_b;
	while (a_rot-- > 0)
		ra(stack, 0);
	while (b_rot-- > 0)
		rrb(stack, 0);
}
