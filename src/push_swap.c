/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:35:06 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 17:52:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->b);
	free (stack->lis_raw);
	free (stack->dp);
	free (stack->prev);
	if (stack->lis_used == 1)
		free (stack->lis);
	exit (0);
}

void	init(t_data *stack)
{
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = calloc(sizeof(int), stack->len);
	stack->lis_raw = (int *)malloc(stack->len * sizeof(int));
	stack->dp = (int *)malloc(stack->len * sizeof(int));
	stack->prev = (int *)malloc(stack->len * sizeof(int));
	stack->last_a = stack->len - 1;
	stack->last_b = 0;
	stack->lis_used = 0;
	stack->move_counter = 0;
}

static int	check_sorted_input(t_data *stack)
{
	int	i;

	i = 1;
	while (i < stack->len)
	{
		if (stack->a[i] < stack->a[i - 1])
			return (1);
		i++;
	}
	ft_cleaner(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		string_input(&stack, argv[1]);
	else
	{
		stack.len = argc - 1;
		init(&stack);
		if (check_input(&stack, argv) == 0)
			return (0);
		fill_stack_a(&stack, argv);
	}
	if (check_sorted_input(&stack) == 0)
		return (0);
	if (stack.len <= 5)
		simple_case(&stack);
	lis_finder(&stack);
	complex_case(&stack);
	print_stack_a(&stack);
	ft_printf("Mosse effettuate: %d\n", stack.move_counter);
	ft_cleaner(&stack);
}
