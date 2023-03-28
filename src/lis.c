/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/28 15:08:35 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_lis(t_data *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->len)
	{
		if (stack->lis[j] == stack->a[0])
		{
			pb(stack);
			j++;
		}
		ra(stack, 0);
		i++;
	}
}

void	find_lis(t_data *stack)
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
	find_max_lis(stack);
	lis_raw_gen(stack);
	//print_lis_raw(stack);
	//ft_printf("%d\n", stack->lis_raw_len);
	lis_gen(stack);
	//print_lis(stack);
	//ft_printf("%d\n", stack->lis_len);
	push_lis(stack);
	print_stack_b(stack);
}
