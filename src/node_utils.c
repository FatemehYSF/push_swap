/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 09:58:39 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/16 12:02:10 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Creates a new stack node with a given integer value.
 *
 * The function allocates memory for a new t_node, initializes its value,
 * sets its next pointer to NULL, and returns the created node.
 *
 * @param value The integer value to store inside the new node.
 * @return t_node* Pointer to the newly created node, 
 * or NULL on allocation failure.
 */
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/**
 * @brief Frees all nodes in a stack and sets the stack pointer to NULL.
 *
 * The function iterates through the linked list, freeing each node.
 * After completion, the stack pointer is set to NULL
 *  to avoid dangling references.
 *
 * @param stack A pointer to the stack pointer (t_node **). Must not be NULL.
 */
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
