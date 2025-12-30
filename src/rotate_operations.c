/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:18:34 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:39:29 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates stack A upward (first element becomes last).
 *
 * If stack A has fewer than two nodes, nothing happens.
 *
 * @param a Pointer to stack A.
 */
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = last_node(*a);
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

/**
 * @brief Rotates stack B upward (first element becomes last).
 *
 * If stack B has fewer than two nodes, nothing happens.
 *
 * @param b Pointer to stack B.
 */
void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = last_node(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

/**
 * @brief Rotates both stacks A and B upward.
 *
 * This function performs the internal rotation logic of ra() and rb()
 * but without printing their instructions. It prints "rr" once after
 * completing both rotations.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	rr(t_node **a, t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (a && *a && (*a)->next)
	{
		first = *a;
		last = last_node(*a);
		*a = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		last = last_node(*b);
		*b = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}
