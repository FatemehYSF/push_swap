/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:32:21 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/18 16:54:48 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element of stack B onto stack A.
 *
 * Removes the first node of stack B and inserts it at the front of stack A.
 * If stack B is empty, the function does nothing.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	add_front(a, temp);
	write(1, "pa\n", 3);
}

/**
 * @brief Pushes the top element of stack A onto stack B.
 *
 * Removes the first node of stack A and inserts it at the front of stack B.
 * If stack A is empty, the function does nothing.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	add_front(b, temp);
	write(1, "pb\n", 3);
}
