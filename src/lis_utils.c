/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:44 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 17:49:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_len(int *stack)
{
	int	i;

	i = 0;
	i = (sizeof(*stack) / sizeof(int));
	return (i);
}

void	lis_check(t_data *stack)
{
	int	i;
	int	j;

	i = 1;
	while (i < stack->len)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] < stack->a[i] && stack->dp[j] + 1 > stack->dp[i])
			{
				stack->dp[i] = stack->dp[j] + 1;
				stack->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	find_max_lis(t_data *stack)
{
	int	i;

	i = 0;
	stack->lis_len = 0;
	while (i < stack->len)
	{
		if (stack->dp[i] > stack->dp[stack->lis_len])
			stack->lis_len = i;
		i++;
	}
}

void	lis_gen(t_data *stack)
{
	int	i;
	int	j;

	i = stack->lis_len;
	j = stack->dp[stack->lis_len] - 1;
	while (i >= 0)
	{
		stack->lis[j] = stack->a[i];
		i = stack->prev[i];
		j--;
	}
}
