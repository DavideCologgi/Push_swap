/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:44 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/27 11:50:00 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_len(int *stack)
{
	int	i;

	i = 0;
	i = (sizeof(*stack) / sizeof(int));
	return (i);
}
