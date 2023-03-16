/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:35:06 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/16 16:08:05 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		digit;
	bool	seen[argc - 1];

	i = 1;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Error\n");
				return(0);
			}
			digit = argv[i][j] - '0';
			if (seen[digit])
			{
				ft_printf("Error\n");
				return (0);
			}
			seen[digit] = true;
			j++;
		}
		i++;
	}
}
