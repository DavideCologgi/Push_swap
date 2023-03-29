/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:57:55 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/28 15:48:57 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack_a(t_data *stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
