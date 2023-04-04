/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/04 15:20:43 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr_move(t_data *stack)
{
	int	a_rot;
	int	b_rot;
	int	n_rot;

	a_rot = stack->last_a - stack->nb_pos + 1;
	b_rot = stack->last_b - stack->next_minor_pos + 1;
	if (a_rot > b_rot)
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

void	rr_move(t_data *stack)
{
	int	a_rot;
	int	b_rot;
	int	n_rot;

	a_rot = stack->nb_pos;
	b_rot = stack->next_minor_pos;
	if (a_rot > b_rot)
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

	a_rot = stack->last_a - stack->nb_pos + 1;
	b_rot = stack->next_minor_pos;
	while (a_rot-- > 0)
		rra(stack, 0);
	while (b_rot-- > 0)
		rb(stack, 0);
}

void	ra_rrb_move(t_data *stack)
{
	int	a_rot;
	int	b_rot;

	a_rot = stack->nb_pos;
	b_rot = stack->last_b - stack->next_minor_pos + 1;
	while (a_rot-- > 0)
		ra(stack, 0);
	while (b_rot-- > 0)
		rrb(stack, 0);
}
