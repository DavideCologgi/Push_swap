/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:33:19 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/04 14:05:49 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sign(char c)
{
	int	sign;

	sign = 1;
	if (c == '-')
		sign *= -1;
	return (sign);
}

int	count_val(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}
