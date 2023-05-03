/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:54:08 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 15:15:36 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack_a(t_data *stack)
{
	int	i;

	i = 0;
	while (i <= stack->last_a)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
}

void	print_stack_b(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->last_b)
	{
		ft_printf("%d\n", stack->b[i]);
		i++;
	}
}
