/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:33:19 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 17:30:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;
	unsigned int	k;

	if (!s)
		return (NULL);
	k = (unsigned int)ft_strlen(s);
	i = 0;
	if (k <= len)
		res = (char *)malloc(k + 1 * sizeof(char));
	else
		res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (NULL);
	if (!(k < start))
	{
		while (s[start] != '\0' && i < len)
		{
			((char *)res)[i] = s[start];
			i++;
			start++;
		}
	}
	res[i] = '\0';
	return (res);
}

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
