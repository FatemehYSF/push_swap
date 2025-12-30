/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:51:49 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/16 12:01:05 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Counts the number of nodes in a stack.
 *
 * Iterates through the linked list and counts how many nodes it contains.
 *
 * @param stack Pointer to the first node of the stack.
 * @return int Number of nodes in the stack.
 */
int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/**
 * @brief Checks whether a stack is sorted in ascending order.
 *
 * The function compares each node with its next one. If any value is greater
 * than the next, the list is considered unsorted.
 *
 * @param stack Pointer to the first node of the stack.
 * @return int Returns 1 if sorted, 0 otherwise.
 */
int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
