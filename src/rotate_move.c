/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/04/04 11:05:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_better_rot_a(t_data *stack, int pos)
{
	if (pos <= (stack->last_a / 2))
		ra(stack, 0);
	else
		rra(stack, 0);
}

void	check_better_rot_b(t_data *stack)
{
	int	next_lower;
	int	pos;
	int	i;

	next_lower = stack->b[0];
	pos = 0;
	i = 0;
	while (i < stack->last_b)
	{
		if (stack->b[i] < stack->a[0] && stack->b[i] > next_lower)
		{
			next_lower = stack->b[i];
			pos = i;
		}
		i++;
	}
}

void	ra(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->last_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->last_a] = tmp;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->last_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->last_b - 1] = tmp;
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_data *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	ft_printf("rr\n");
}
