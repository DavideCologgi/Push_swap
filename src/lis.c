/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/22 16:24:27 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Funzione che controlla se il lis e' stato creato correttamente
static void	print_lis(int *lis, int lis_len)
{
	int	i;

	i = 0;
	while (i < lis_len)
	{
		ft_printf("%d\n", lis[i]);
		i++;
	}
}

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
	int	seq[stack->len];
	int	seq_len = 0;
	int	lis_len = 0;
	int	i, j;

	i = 0;
	while (i < stack->len)
	{
		lis[i] = 0;
		seq[i] = 0;
		i++;
	}
	i = 0;
	while (i < stack->len)
	{
		seq[seq_len] = stack->a[i];
		seq_len++;
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->a[j] > seq[seq_len - 1])
			{
				seq[seq_len] = stack->a[j];
				seq_len++;
			}
			j++;
		}
		if (seq_len > lis_len)
		{
			lis_len = seq_len;
			j = 0;
			while (j < seq_len)
			{
				lis[j] = seq[j];
				j++;
			}
		}
		i++;
		seq_len = 0;
	}
	print_lis(lis, lis_len);
	keep_lis(stack, lis);
}
