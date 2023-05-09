/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:35:06 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/09 11:04:49 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	pb(&stack, 0);
	pb(&stack, 0);
	if (stack.b[0] < stack.b[1])
		sb(&stack, 0);
	complex_case(&stack);
	ft_cleaner(&stack);
}
