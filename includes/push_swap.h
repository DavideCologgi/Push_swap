/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:33:16 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/02 17:52:55 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_data{
	int	*a;
	int	*b;

	int	*lis_raw;
	int	*lis;
	int	*dp;
	int	*prev;
	int	len;
	int	lis_raw_len;
	int	lis_len;
	int	lis_used;

	int	last_a;
	int	last_b;
	int	move_counter;

	int	min;
	int	min_pos;
	int	max;
	int	max_pos;

	int	a_moves;
	int	b_moves;
	int	tot_moves;
	int	best_moves;
	int	a_pos;
	int	b_pos;
	int	best_pos_a;
	int	best_pos_b;
	int	best_nb;
}	t_data;

// Funzioni base, funzioni per il lis e funzioni per gli stack <= 5
int		ft_is_digit(char c);
int		ft_abs(int nb);
int		ft_atoi(const char *str);
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
void	init(t_data *stack);
void	fill_stack_a(t_data *stack, char **argv);
void	lis_finder(t_data *stack);
void	keep_lis(t_data *stack);
void	lis_raw_check(t_data *stack);
void	find_max_pos_lis(t_data *stack);
void	lis_raw_gen(t_data *stack);
void	lis_gen(t_data *stack);
void	simple_case(t_data *stack);
void	sort_2(t_data *stack);
void	sort_3(t_data *stack);
void	sort_4(t_data *stack);
void	sort_5(t_data *stack);
void	find_min(t_data *stack);
void	find_max(t_data *stack);
void	push_min(t_data *stack);
void	push_max(t_data *stack);
void	check_better_rot_a(t_data *stack, int pos);
void	check_better_rot_b(t_data *stack);

// Funzioni per uno stack > 5
void	get_max(t_data *stack);
void	get_min(t_data *stack);
void	complex_case(t_data *stack);
void	find_best_nb_to_push(t_data *stack);
void	find_where_to_push(t_data *stack, int nb);
void	nb_is_between(t_data *stack, int nb);
void	push_nb(t_data *stack);
void	rrr_move(t_data *stack);
void	rr_move(t_data *stack);
void	rra_rb_move(t_data *stack);
void	ra_rrb_move(t_data *stack);
void	assign_best_nb(t_data *stack, int a, int b, int i);

// Funzione che libera la memoria
void	ft_cleaner(t_data *stack);

// Funzioni di controllo per stampare gli stack
void	print_stack_a(t_data *stack);
void	print_stack_b(t_data *stack);
void	print_lis(t_data *stack);
void	print_lis_raw(t_data *stack);

// Funzioni per input di tipo stringa
int		ft_sign(char c);
int		is_valid(char *argv);
int		count_val(char **temp);
int		control_doubles(t_data *stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	print_error(void);
void	string_input(t_data *stack, char *argv);
void	*ft_cicle(char const *s, char **str, char c, unsigned int count);
void	control_fill_stack(t_data *stack, char **temp);
size_t	ft_strlen(const char *str);

#endif
