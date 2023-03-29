/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:30:47 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/29 17:35:11 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_data *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack, 0);
}

void	sort_3(t_data *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[2] > stack->a[0]) // 2 1 3
		sa(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[2] < stack->a[0]) // 3 1 2
		ra(stack, 0);
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2]) // 2 3 1
		rra(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]) // 3 2 1
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	if (stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2]) // 1 3 2
	{
		sa(stack, 0);
		ra(stack, 0);
	}
}

void	sort_4(t_data *stack)
{
	int	i;

	i = 0;
	find_min(stack);
	while (i < stack->len)
	{
		if (stack->a[0] == stack->min)
			pb(stack);
		else
		{
			if (stack->last_a > 2)
				ra(stack, 0);
		}
		i++;
	}
	sort_3(stack);
	pa(stack);
}

void	sort_5(t_data *stack)
{
	int	i;

	i = 0;
	find_min(stack);
	find_max(stack);
	while (i < stack->len)
	{
		if (stack->a[0] == stack->max || stack->a[0] == stack->min)
			pb(stack);
		else
		{
			if (stack->last_a > 2)
				ra(stack, 0);
		}
		i++;
	}
	sort_3(stack);
	if (stack->b[0] > stack->b[1])
		sb(stack, 0);
	pa(stack);
	pa(stack);
	ra(stack, 0);
}

void	simple_case(t_data *stack)
{
	if (stack->len == 2)
	{
		sort_2(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 3)
	{
		sort_3(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 4)
	{
		sort_4(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 5)
	{
		sort_5(stack);
		ft_cleaner(stack);
	}
}
