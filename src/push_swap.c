/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:35:06 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 17:29:32 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->lis);
}

int	main(int argc, char **argv)
{
	t_data	stack;

	if (argc < 2)
		return (0);
	stack.len = argc - 1;
	if (check_input(&stack, argv) == 0)
		return (0);
	fill_stack_a(&stack, argv);
	find_lis(&stack);
	ft_cleaner(&stack);
}
