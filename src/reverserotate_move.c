/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:55:46 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 18:39:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	tmp = stack->a[stack->len - 1];
	i = 0;
	while (i < stack->len)
	{
		stack->a[stack->len - i] = stack->a[stack->len - i - 1];
		i++;
	}
	stack->a[0] = tmp;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_data *stack, int flag)
{
	int	tmp;
	int	i;

	tmp = stack->b[stack->len - 1];
	i = 0;
	while (i < stack->len)
	{
		stack->b[stack->len - i] = stack->b[stack->len - i - 1];
		i++;
	}
	stack->b[0] = tmp;
	if (flag == 0)
		ft_printf("rrb\n");
}

void	rrr(t_data *stack)
{
	rra(stack, 1);
	rrb(stack, 1);
	ft_printf("rrr\n");
}
