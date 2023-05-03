/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:30:39 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 17:05:19 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

// int	combo(t_data *stack, int a, int b)
// {
// 	if (stack->a_pos > (stack->last_a / 2)
// 		&& (stack->b_pos > ((stack->last_b - 1) / 2)))
// 	{
// 		a = (stack->last_a - stack->a_pos + 1);
// 		b = stack->last_b - stack->b_pos;
// 		if (a > b)
// 			stack->tot_moves = a;
// 		else
// 			stack->tot_moves = b;
// 	}
// 	else if (stack->a_pos <= (stack->last_a / 2)
// 		&& (stack->b_pos <= ((stack->last_b - 1) / 2)))
// 	{
// 		a = stack->a_pos;
// 		b = stack->b_pos;
// 		if (a > b)
// 			stack->tot_moves = a;
// 		else
// 			stack->tot_moves = b;
// 	}
// 	return (a, b);
// }

// int	not_combo(t_data *stack, int a, int b)
// {
// 	if (stack->a_pos > (stack->last_a / 2)
// 		&& (stack->b_pos <= ((stack->last_b - 1) / 2)))
// 	{
// 		a = (stack->last_a - stack->a_pos + 1);
// 		b = stack->b_pos;
// 		stack->tot_moves = a + b;
// 	}
// 	else if (stack->a_pos <= (stack->last_a / 2)
// 		&& (stack->b_pos > ((stack->last_b - 1) / 2)))
// 	{
// 		a = stack->a_pos;
// 		b = stack->last_b - stack->b_pos;
// 		stack->tot_moves = a + b;
// 	}
// 	return (a, b);
// }
