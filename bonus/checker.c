/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:11:46 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/08 14:40:31 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_check(t_data *stack)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (i < stack->len)
	{
		if (stack->a[i] < stack->a[i - 1])
		{
			flag = 0;
			break ;
		}
		i++;
	}
	if (flag == 1)
		ft_printf("OK");
	else
		ft_printf("KO");
	if (stack->a)
		free (stack->a);
	if (stack->b)
		free (stack->b);
}

void	check_rotate_input(t_data *stack, char *str)
{
	if (ft_strcmp(str, "ra\n") == 1)
		ra(stack, 1);
	else if (ft_strcmp(str, "rb\n") == 1)
		rb(stack, 1);
	else if (ft_strcmp(str, "rr\n") == 1)
		rr(stack, 1);
	else if (ft_strcmp(str, "rra\n") == 1)
		rra(stack, 1);
	else if (ft_strcmp(str, "rrb\n") == 1)
		rrb(stack, 1);
	else if (ft_strcmp(str, "rrr\n") == 1)
		rrr(stack, 1);
	else
		wrong_input(stack);
}

void	valid_move_checker(t_data *stack, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "\n") == 1)
			return ;
		if (ft_strcmp(str, "sa\n") == 1)
			sa(stack, 1);
		else if (ft_strcmp(str, "sb\n") == 1)
			sb(stack, 1);
		else if (ft_strcmp(str, "ss\n") == 1)
			ss(stack, 1);
		else if (ft_strcmp(str, "pa\n") == 1)
			pa(stack, 1);
		else if (ft_strcmp(str, "pb\n") == 1)
			pb(stack, 1);
		else
			check_rotate_input(stack, str);
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	stack;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		string_input(&stack, argv[1]);
	else if (argc > 2)
	{
		stack.len = argc - 1;
		init(&stack);
		if (check_input(&stack, argv) == 0)
			return (0);
		fill_stack_a(&stack, argv);
	}
	if (check_sorted_input(&stack) == 0)
		return (0);
	valid_move_checker(&stack, get_next_line(0));
	final_check(&stack);
}
