/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 13:40:35 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Funzione che controlla se il lis e' stato creato correttamente
static void	print_lis(t_data *stack, int lis_len)
{
	int	i;

	i = 0;
	while (i < lis_len)
	{
		ft_printf("%d\n", stack->lis[i]);
		i++;
	}
}

void	keep_lis(t_data *stack)
{
	int	i;
	int	j;
	int	lis_len;

	i = 1;
	lis_len = get_stack_len(stack->lis);
	while (i < lis_len)
	{
		j = 0;
		while (j < stack->len)
		{
			if (stack->a[j] == stack->lis[i])
			{
				while (stack->a[0] != stack->lis[i])
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
	int	dp[stack->len];
	int	prev[stack->len];
	int	lis_len;
	int	i;
	int	j;

	// Inizializzazione degli array dp e prev
	i = 0;
	stack->lis = (int *)malloc(stack->len * sizeof(int));
	lis_len = 0;
	while (i < stack->len)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}

	// Calcolo della LIS
	i = 1;
	while (i < stack->len)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] < stack->a[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}

	// Trovare la lunghezza massima della LIS
	i = 0;
	while (i < stack->len)
	{
		if (dp[i] > dp[lis_len])
			lis_len = i;
		i++;
	}

	// Ricostruzione della LIS
	i = lis_len;
	j = dp[lis_len] - 1;
	while (i >= 0)
	{
		stack->lis[j] = stack->a[i];
		i = prev[i];
		j--;
	}
	print_lis(stack, dp[lis_len]);
	keep_lis(stack);
}
