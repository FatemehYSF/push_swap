/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:20:30 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:43:10 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Reverse rotates stack A (last element becomes first).
 *
 * Moves the last node of stack A to the front. If the stack contains
 * fewer than two nodes, nothing happens.
 *
 * @param a Pointer to stack A.
 */
void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;
	t_node	*current;

	if (!a || !*a || !(*a)->next)
		return ;
	current = *a;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

/**
 * @brief Reverse rotates stack B (last element becomes first).
 *
 * @param b Pointer to stack B.
 */
void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;
	t_node	*current;

	if (!b || !*b || !(*b)->next)
		return ;
	current = *b;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

/**
 * @brief Performs reverse rotate on a single stack without printing.
 *
 * @param stack Pointer to the stack to modify.
 */
static void	silent_reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;
	t_node	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	last = current;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/**
 * @brief Reverse rotates both stacks A and B and prints "rrr".
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	rrr(t_node **a, t_node **b)
{
	silent_reverse_rotate(a);
	silent_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
