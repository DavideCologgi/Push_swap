/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:30:39 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/08 14:26:02 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case1(t_data *stack)
{
	stack->a_tmp = (stack->last_a - stack->a_pos + 1);
	stack->b_tmp = stack->last_b - stack->b_pos;
	if (stack->a_tmp > stack->b_tmp)
		stack->tot_moves = stack->a_tmp;
	else
		stack->tot_moves = stack->b_tmp;
}

void	case2(t_data *stack)
{
	stack->a_tmp = stack->a_pos;
	stack->b_tmp = stack->b_pos;
	if (stack->a_tmp > stack->b_tmp)
		stack->tot_moves = stack->a_tmp;
	else
		stack->tot_moves = stack->b_tmp;
}

void	case3(t_data *stack)
{
	stack->a_tmp = (stack->last_a - stack->a_pos + 1);
	stack->b_tmp = stack->b_pos;
	stack->tot_moves = stack->a_tmp + stack->b_tmp;
}

void	case4(t_data *stack)
{
	stack->a_tmp = stack->a_pos;
	stack->b_tmp = stack->last_b - stack->b_pos;
	stack->tot_moves = stack->a_tmp + stack->b_tmp;
}
