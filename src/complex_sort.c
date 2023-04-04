/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/04 16:39:23 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_next_minor(t_data *stack, int nb)
{
	int	i;

	i = 0;
	stack->next_min = get_min(stack);
	while (i < stack->last_b)
	{
		if (nb > stack->b[i] && stack->b[i] > stack->next_min)
		{
			stack->next_min = stack->b[i];
			stack->next_minor_pos = i;
		}
		i++;
	}
	ft_printf("-----------\n");
	ft_printf("%d\n", stack->next_min);
	ft_printf("-----------\n");
	if (stack->next_minor_pos > stack->last_b / 2)
		return (stack->last_b - stack->next_minor_pos + 1);
	else
		return (stack->next_minor_pos);
}

void	find_best_nb_to_push(t_data *stack)
{
	int	i;

	i = 0;
	stack->min_moves = stack->last_a / 2;
	stack->nb_to_push = stack->a[0];
	stack->nb_pos = i;
	while (i <= stack->last_a)
	{
		stack->num_moves = 0;
		if (i > stack->last_a / 2)
			stack->num_moves += stack->last_a - i + 1;
		else
			stack->num_moves += i;
		stack->num_moves += find_next_minor(stack, stack->a[i]);
		if (stack->num_moves < stack->min_moves)
		{
			stack->min_moves = stack->num_moves;
			stack->nb_to_push = stack->a[i];
			stack->nb_pos = i;
		}
		i++;
	}
}

void	combo_move(t_data *stack)
{
	if ((stack->nb_pos > stack->last_a / 2)
		&& (stack->next_minor_pos > stack->last_b / 2))
	{
		rrr_move(stack);
		pb(stack);
	}
	else if ((stack->nb_pos > stack->last_a / 2)
		&& (stack->next_minor_pos <= stack->last_b / 2))
	{
		rra_rb_move(stack);
		pb(stack);
	}
	else if ((stack->nb_pos <= stack->last_a / 2)
		&& (stack->next_minor_pos <= stack->last_b / 2))
	{
		rr_move(stack);
		pb(stack);
	}
	else
	{
		ra_rrb_move(stack);
		pb(stack);
	}
}

void	complex_case(t_data *stack)
{
	while (stack->last_a >= 0)
	{
		find_best_nb_to_push(stack);
		combo_move(stack);
		ft_printf("-----------\n");
		print_stack_b(stack);
		ft_printf("-----------\n");
	}
	while (stack->last_b > 0)
		pa(stack);
	find_min(stack);
	while (stack->a[0] != stack->min)
		check_better_rot_a(stack, stack->min_pos);
	print_stack_a(stack);
}
