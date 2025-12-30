/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:58:39 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/29 14:15:22 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the last node of a stack.
 *
 * Traverses the linked list until the node whose `next` pointer is NULL
 * is found. This node represents the bottom of the stack.
 *
 * @param stack Pointer to the first node of the stack.
 * @return t_node* Pointer to the last node, or NULL if the stack is empty.
 */
t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Adds a node to the front (top) of the stack.
 *
 * This function adjusts pointers so the new node becomes the new head
 * of the stack.
 *
 * @param stack A pointer to the stack pointer.
 * @param new Pointer to the node to add. Must not be NULL.
 */
void	add_front(t_node **stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

/**
 * @brief Adds a node to the end of the stack.
 *
 * If the stack is empty, the new node becomes the first element.
 * Otherwise, it is appended to the last node.
 *
 * @param stack A pointer to the stack pointer.
 * @param new Pointer to the node to add. Must not be NULL.
 */
void	add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = last_node(*stack);
	last->next = new;
}
