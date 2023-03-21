/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:33:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/21 11:02:28 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_data{
	int		*a;
	int		*b;
	int		len;
	int		last_pos;
	char	*last_move;
}	t_data;

int		ft_is_digit(char c);
int		ft_atoi(const char *str);
int		check_input(t_data *stack, char **argv);
int		check_if_double(int nb, int	*array, int pos);
void	sa(t_data *stack);
void	sb(t_data *stack);
void	ss(t_data *stack);
void	pa(t_data *stack);
void	pb(t_data *stack);
void	ra(t_data *stack);
void	rb(t_data *stack);
void	rr(t_data *stack);
void	rra(t_data *stack);
void	rrb(t_data *stack);
void	rrr(t_data *stack);
void	check_last_a(t_data *stack);
void	check_last_b(t_data *stack);
void	fill_stack_a(t_data *stack, char **argv);

#endif
