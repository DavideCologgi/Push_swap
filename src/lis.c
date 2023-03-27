/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 18:28:55 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	print_lis(t_data *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->lis_len)
// 	{
// 		ft_printf("%d\n", stack->lis[i]);
// 		i++;
// 	}
// }

void	push_lis(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->lis_len)
	{
		while (stack->a[0] != stack->lis[i])
			ra(stack, 0);
		rrb(stack, 0);
		pb(stack);
		i++;
	}
	print_stack(stack);
}

void	find_lis(t_data *stack)
{
	int	i;

	i = 0;
	stack->lis = (int *)malloc(stack->len * sizeof(int));
	stack->dp = (int *)malloc(stack->len * sizeof(int));
	stack->prev = (int *)malloc(stack->len * sizeof(int));
	while (i < stack->len)
	{
		stack->lis[i] = 0;
		stack->dp[i] = 1;
		stack->prev[i] = -1;
		i++;
	}
	lis_check(stack);
	find_max_lis(stack);
	lis_gen(stack);
	//print_lis(stack);
	//ft_printf("%d\n", stack->lis_len);
	push_lis(stack);
}
