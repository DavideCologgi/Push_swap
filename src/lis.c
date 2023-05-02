/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 14:21:24 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_lis(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->lis_len)
	{
		while (stack->lis[i] != stack->a[0])
			ra(stack, 0);
		pb(stack);
		i++;
	}
}

void	lis_finder(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		stack->lis_raw[i] = 0;
		stack->dp[i] = 1;
		stack->prev[i] = -1;
		i++;
	}
	lis_raw_check(stack);
	find_max_pos_lis(stack);
	lis_raw_gen(stack);
	lis_gen(stack);
	push_lis(stack);
	stack->lis_used = 1;
	printf("-----------\n");
	print_stack_b(stack);
	printf("-----------\n");
	print_stack_a(stack);
	printf("-----------\n");
}
