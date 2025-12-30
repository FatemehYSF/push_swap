/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:57:18 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/18 16:59:15 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of stack A.
 *
 * If stack A contains fewer than two nodes, the function does nothing.
 *
 * @param a Pointer to stack A.
 */
void	sa(t_node **a)
{
	int	temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	write(1, "sa\n", 3);
}

/**
 * @brief Swaps the first two elements of stack B.
 *
 * If stack B contains fewer than two nodes, the function does nothing.
 *
 * @param b Pointer to stack B.
 */
void	sb(t_node **b)
{
	int	temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	write(1, "sb\n", 3);
}

/**
 * @brief Swaps the first two elements of both stacks A and B.
 *
 * If a stack has fewer than two nodes, its swap is skipped.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	ss(t_node **a, t_node **b)
{
	int	temp;

	if (a && *a && (*a)->next)
	{
		temp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = temp;
	}
	if (b && *b && (*b)->next)
	{
		temp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = temp;
	}
	write(1, "ss\n", 3);
}
