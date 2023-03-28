/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:35:06 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/28 14:57:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->lis);
}

static void	init(t_data *stack, int argc)
{
	stack->len = argc - 1;
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = calloc(sizeof(int), stack->len);
	stack->lis_raw = (int *)malloc(stack->len * sizeof(int));
	stack->dp = (int *)malloc(stack->len * sizeof(int));
	stack->prev = (int *)malloc(stack->len * sizeof(int));
	stack->last_a = stack->len - 1;
	stack->last_b = 0;
}

int	main(int argc, char **argv)
{
	t_data	stack;

	if (argc < 2)
		return (0);
	init(&stack, argc);
	stack.len = argc - 1;
	if (check_input(&stack, argv) == 0)
		return (0);
	fill_stack_a(&stack, argv);
	find_lis(&stack);
	ft_cleaner(&stack);
}
