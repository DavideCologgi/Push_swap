/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/08 14:28:53 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_nb(t_data *stack)
{
	if ((stack->best_pos_a > stack->last_a / 2)
		&& (stack->best_pos_b > ((stack->last_b - 1) / 2)))
	{
		rrr_move(stack);
		pb(stack, 0);
	}
	else if ((stack->best_pos_a <= stack->last_a / 2)
		&& (stack->best_pos_b <= ((stack->last_b - 1) / 2)))
	{
		rr_move(stack);
		pb(stack, 0);
	}
	else if ((stack->best_pos_a > stack->last_a / 2)
		&& (stack->best_pos_b <= ((stack->last_b - 1) / 2)))
	{
		rra_rb_move(stack);
		pb(stack, 0);
	}
	else
	{
		ra_rrb_move(stack);
		pb(stack, 0);
	}
}

void	find_where_to_push(t_data *stack, int nb)
{
	get_min(stack);
	get_max(stack);
	if (nb > stack->max || nb < stack->min)
		stack->b_pos = stack->max_pos;
	else
		nb_is_between(stack, nb);
}

void	find_best_nb_to_push(t_data *stack)
{
	int	i;

	i = 0;
	while (i <= stack->last_a)
	{
		stack->a_pos = i;
		find_where_to_push(stack, stack->a[i]);
		if (stack->a_pos > (stack->last_a / 2)
			&& (stack->b_pos > ((stack->last_b - 1) / 2)))
			case1(stack);
		else if (stack->a_pos <= (stack->last_a / 2)
			&& (stack->b_pos <= ((stack->last_b - 1) / 2)))
			case2(stack);
		else if (stack->a_pos > (stack->last_a / 2)
			&& (stack->b_pos <= ((stack->last_b - 1) / 2)))
			case3(stack);
		else
			case4(stack);
		if (stack->tot_moves < stack->best_moves)
			assign_best_nb(stack, i);
		i++;
	}
}

void	complex_case(t_data *stack)
{
	while (stack->last_a >= 0)
	{
		stack->best_moves = stack->len ;
		stack->best_pos_a = 0;
		stack->best_pos_b = (stack->last_b - 1) / 2;
		find_best_nb_to_push(stack);
		push_nb(stack);
	}
	get_min(stack);
	while (stack->b[stack->last_b - 1] != stack->min)
	{
		if (stack->min_pos > (stack->last_b - 1) / 2)
			rrb(stack, 0);
		else
			rb(stack, 0);
	}
	while (stack->last_b > 0)
		pa(stack, 0);
}
