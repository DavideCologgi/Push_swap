/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:39:01 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/21 11:01:22 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *stack)
{
	int	tmp;

	if (stack->a[0] != 0 && stack->a[1] != 0)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	ft_printf("sa\n");
}

void	sb(t_data *stack)
{
	int	tmp;

	if (stack->b[0] != 0 && stack->b[1] != 0)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_data *stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}

void	pa(t_data *stack)
{
	int	i;

	if (stack->b[0] != 0)
	{
		check_last_a(stack);
		while (stack->last_pos >= 0)
		{
			stack->a[stack->last_pos + 1] = stack->a[stack->last_pos];
			stack->last_pos--;
		}
		stack->a[0] = stack->b[0];
		check_last_b(stack);
		i = 0;
		while (i < stack->last_pos)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = 0;
	}
}

void	pb(t_data *stack)
{
	int	i;

	if (stack->a[0] != 0)
	{
		check_last_b(stack);
		while (stack->last_pos >= 0)
		{
			stack->b[stack->last_pos + 1] = stack->b[stack->last_pos];
			stack->last_pos--;
		}
		stack->b[0] = stack->a[0];
		check_last_a(stack);
		i = 0;
		while (i < stack->last_pos)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = 0;
	}
}
