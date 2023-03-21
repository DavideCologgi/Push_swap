/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:33 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/21 10:50:44 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	keep_lis(t_data *stack, int *lis)
{

}

void	find_lis(t_data *stack)
{
	int	*lis;
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
