/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:39:01 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/28 14:53:30 by dcologgi         ###   ########.fr       */
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
		ft_printf("sa\n");
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
		ft_printf("sb\n");
}

void	ss(t_data *stack)
{
	sa(stack, 1);
	sb(stack, 1);
	ft_printf("ss\n");
}

void	pa(t_data *stack)
{
	if (stack->last_b >= 0)
	{
		rra(stack, 1);
		stack->a[0] = stack->b[0];
		stack->last_a++;
		rb(stack, 1);
		stack->last_b--;
		ft_printf("pa\n");
	}
}

void	pb(t_data *stack)
{
	if (stack->last_a >= 0)
	{
		rrb(stack, 1);
		stack->b[0] = stack->a[0];
		stack->last_b++;
		ra(stack, 1);
		stack->last_a--;
		ft_printf("pb\n");
	}
}
