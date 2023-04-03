/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/03 16:04:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_next_minor(t_data *stack)
{
	int	i;

	i = 0;
	stack->next_min = stack->b[0];
	stack->next_minor_pos = 0;
	while (i < stack->last_b)
	{
		if (stack->a[0] > stack->b[i] && stack->b[i] > stack->next_min)
		{
			stack->next_min = stack->b[i];
			stack->next_minor_pos = i;
		}
		i++;
	}
	if (stack->next_minor_pos > stack->last_b / 2)
		return (stack->last_b - stack->next_minor_pos + 1);
	else
		return (stack->next_minor_pos);
}

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

void	move1(t_data *stack)
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

void	move2(t_data *stack)
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
