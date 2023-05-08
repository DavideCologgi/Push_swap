/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:39:01 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 10:25:44 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *stack, int flag)
{
	int	tmp;

	if (stack->a[0] != 0 && stack->a[1] != 0)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (flag == 0)
	{
		ft_printf("sa\n");
		stack->move_counter++;
	}
}

void	sb(t_data *stack, int flag)
{
	int	tmp;

	if (stack->b[0] != 0 && stack->b[1] != 0)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	if (flag == 0)
	{
		ft_printf("sb\n");
		stack->move_counter++;
	}
}

void	ss(t_data *stack, int flag)
{
	sa(stack, 1);
	sb(stack, 1);
	if (flag == 0)
		ft_printf("ss\n");
	stack->move_counter++;
}

void	pa(t_data *stack, int flag)
{
	int	i;

	i = 0;
	if (stack->last_b >= 0)
	{
		while (i <= stack->last_a)
		{
			stack->a[stack->last_a - i + 1] = stack->a[stack->last_a - i];
			i++;
		}
		stack->a[0] = stack->b[0];
		stack->last_a++;
		rb(stack, 1);
		stack->last_b--;
		if (flag == 0)
			ft_printf("pa\n");
		stack->move_counter++;
	}
}

void	pb(t_data *stack, int flag)
{
	int	i;

	i = 0;
	if (stack->last_a >= 0)
	{
		while (i <= stack->last_b)
		{
			stack->b[stack->last_b - i + 1] = stack->b[stack->last_b - i];
			i++;
		}
		stack->b[0] = stack->a[0];
		stack->last_b++;
		ra(stack, 1);
		stack->last_a--;
		if (flag == 0)
			ft_printf("pb\n");
		stack->move_counter++;
	}
}
