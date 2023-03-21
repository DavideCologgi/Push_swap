/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/21 15:47:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	keep_lis(t_data *stack, int *lis)
{
	int	i;
	int	j;
	int	lis_len;

	i = 1;
	lis_len = sizeof(*lis) / sizeof(int);
	while (i < lis_len)
	{
		j = 0;
		while (j < stack->len)
		{
			if (stack->a[j] == lis[i])
			{
				while (stack->a[0] != lis[i])
				{
					if (check_better_rot(stack, j))
						ra(stack, 0);
					else
						rra(stack, 0);
				}
				pb(stack);
			}
			j++;
		}
		i++;
	}
}

void	find_lis(t_data *stack)
{
	int	lis[stack->len];
	int	i;
	int	j;

	i = 1;
	while (i < stack->len)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (stack->a[i] > stack->a[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	keep_lis(stack, lis);
}
