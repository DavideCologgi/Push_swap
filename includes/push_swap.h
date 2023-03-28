/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:33:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/28 11:33:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_data{
	int		*a;
	int		*b;
	int		*lis_raw;
	int		*lis;
	int		*dp;
	int		*prev;
	int		len;
	int		lis_raw_len;
	int		lis_len;
	int		last_a;
	int		last_b;
}	t_data;

int		ft_is_digit(char c);
int		ft_atoi(const char *str);
int		check_better_rot_a(t_data *stack, int pos);
int		check_input(t_data *stack, char **argv);
int		check_if_double(int nb, int	*array, int pos);
void	sa(t_data *stack, int flag);
void	sb(t_data *stack, int flag);
void	ss(t_data *stack);
void	pa(t_data *stack);
void	pb(t_data *stack);
void	ra(t_data *stack, int flag);
void	rb(t_data *stack, int flag);
void	rr(t_data *stack);
void	rra(t_data *stack, int flag);
void	rrb(t_data *stack, int flag);
void	rrr(t_data *stack);
void	check_last_a(t_data *stack);
void	check_last_b(t_data *stack);
void	fill_stack_a(t_data *stack, char **argv);
void	find_lis(t_data *stack);
void	keep_lis(t_data *stack);
void	lis_raw_check(t_data *stack);
void	find_max_lis(t_data *stack);
void	lis_raw_gen(t_data *stack);
void	lis_gen(t_data *stack);

void	print_stack_a(t_data *stack);
void	print_stack_b(t_data *stack);
void	print_lis(t_data *stack);
void	print_lis_raw(t_data *stack);

#endif
