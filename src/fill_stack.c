/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:57:55 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/22 16:21:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Funzione che controlla se lo stack_a e' stato creato correttamente
static void	print_stack_a(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
}
*/
void	fill_stack_a(t_data *stack, char **argv)
{
	int	i;

	i = 0;
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = stack->a;
	while (argv[i + 1])
	{
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	//print_stack_a(stack);
}

void	check_last_a(t_data *stack)
{
	int	i;

	stack->last_pos = 0;
	i = 0;
	while (stack->a[i] != 0)
		stack->last_pos++;
}

void	check_last_b(t_data *stack)
{
	int	i;

	stack->last_pos = 0;
	i = 0;
	while (stack->b[i] != 0)
		stack->last_pos++;
}
