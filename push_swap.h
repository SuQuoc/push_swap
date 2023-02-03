/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:31:18 by qtran             #+#    #+#             */
/*   Updated: 2023/02/03 18:18:08 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/ft_printf.h"
# include <stdio.h>

# define INT_MIN "-2147483648"
# define INT_MAX "2147483647"

typedef struct s_data
{
	int				list_size;
}					t_data;

typedef struct s_node
{
	int				numb;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//t_node				*ft_lstnew(int number);
//void				ft_lstadd_front(t_node **lst, t_node *new);
//void				ft_lstadd_back(t_node **lst, t_node *new);

//--------main and others ----------
int					count_stack_contents(char **arr);
int					find_median(int size, t_node *head);

//-------input handling-------------
int					check_arg_count(char **arr);
int					check_if_numeric(char *str);
int					check_int_range(char **arr);
int					check_double(char **arr);
int					check_if_sorted(char **arr);
char				*create_str(char **av);
void				free_2d_arr(char **arr);

//-------list functions-------------
t_node				*create_double_ll(char **arr);
t_node				*create_empty_stack(int size);
t_node				*addnode(int number);
t_node				*create_node(int number);
t_node				*create_empty_node(void);
void				print_ll(t_node *head);
void				free_ll(t_node *head);
void				free_ll_prev(t_node *head);
void				addnode_front(t_node *new, t_node **head);
void				addnode_back(t_node **head, t_node *new);
void				push_from_to(t_node **from, t_node **to);

#endif
