/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:09:37 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 11:02:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../includes/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// Funzioni per get_next_line
int		ft_stringlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

// Funzioni del checker
int		ft_strcmp(char *s1, char *s2);
void	final_check(t_data *stack);
void	wrong_input(t_data *stack);
void	check_rotate_input(t_data *stack, char *str);
void	valid_move_checker(t_data *stack, char *str);

#endif
