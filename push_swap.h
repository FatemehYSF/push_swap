/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:33:57 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/30 14:55:02 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

/* ========== STRUCT ========== */

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* ========== NODE / LIST ========== */

t_node	*new_node(int value);
void	add_front(t_node **stack, t_node *new);
void	add_back(t_node **stack, t_node *new);
t_node	*last_node(t_node *stack);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);

/* ========== ERROR ========== */

void	error_exit(void);
void	free_tokens(char **tokens);
void	free_all_and_exit(t_node **a, char **tokens);

/* ========== PARSING ========== */

int		is_valid_number(char *str);
int		safe_atoi(char *str, t_node **a, char **tokens);
char	*join_args(int argc, char **argv);
char	**split_tokens(char *joined);
int		check_duplicates(t_node *stack, int value);
void	fill_stack(t_node **a, char **tokens);

/* ========== INDEXING ========== */

void	index_stack(t_node *a);

/* ========== PUSH ========== */

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

/* ========== SWAP ========== */

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* ========== ROTATE ========== */

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* ========== REVERSE ROTATE ========== */

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* ========== SMALL SORT ========== */

void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);

/* ========== RADIX SORT ========== */

void	radix_sort(t_node **a, t_node **b);

/* ========== SORT ========== */

void	sort_stack(t_node **a, t_node **b);

#endif
