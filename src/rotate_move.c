/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/22 16:24:04 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_better_rot(t_data *stack, int pos)
{
	if (pos <= (stack->len / 2))
		return (1);
	return (0);
}

void	ra(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->a[0];
	check_last_a(stack);
	while (i < stack->last_pos)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->last_pos] = tmp;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[0];
	check_last_b(stack);
	while (i < stack->last_pos)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->last_pos] = tmp;
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_data *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	ft_printf("rr\n");
}
