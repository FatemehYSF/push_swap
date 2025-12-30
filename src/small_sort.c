/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:52:43 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:38:05 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Sorts a stack of exactly 3 indexed values (0, 1, 2).
 *
 * Uses sa, ra, and rra depending on the arrangement. Assumes the stack
 * contains exactly three nodes and all values are unique and indexed.
 *
 * @param a Pointer to stack A.
 */
void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && x > z && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

/**
 * @brief Returns the position (index) of a value in the stack.
 *
 * Searches through the linked list until it finds the first node whose
 * value matches the given target. Positions start at 0.
 *
 * @param a Pointer to the first node of stack A.
 * @param value Value to search for.
 * @return int Index of the value if found, otherwise -1.
 */
static int	pos_of(t_node *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

/**
 * @brief Efficiently rotates stack A to bring a target element to the top.
 *
 * Given the current position of an element in stack A, this function applies
 * the minimum number of rotations needed to move that element to the top.
 * 
 * If the element lies in the first half of the stack, upward rotations (ra)
 * are used. If it lies in the second half, downward rotations (rra) are
 * more efficient. This minimizes total operations and improves performance
 * when sorting small stacks (4–5 elements).
 *
 * @param a   Pointer to stack A.
 * @param pos Current index of the target element within stack A.
 */
static void	bring_to_top(t_node **a, int pos)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

/**
 * @brief Sorts a stack of 4 indexed values using push and small sort.
 *
 * Steps:
 * 1. Find the smallest value (0).
 * 2. Rotate stack A until it is on top.
 * 3. Push it to B (pb).
 * 4. Sort the remaining 3 elements.
 * 5. Push the smallest back to A (pa).
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	sort_four(t_node **a, t_node **b)
{
	int	pos;

	pos = pos_of(*a, 0);
	bring_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

/**
 * @brief Sorts a stack of 5 indexed values using push and small sorting.
 *
 * Steps:
 * 1. Push smallest (0) to B.
 * 2. Push second smallest (1) to B.
 * 3. Sort the remaining 3 values on A.
 * 4. Push back the two smallest values from B.
 *
 * Because values are indexed, pushing back (pa, pa) produces correct order.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	sort_five(t_node **a, t_node **b)
{
	int	pos;

	pos = pos_of(*a, 0);
	bring_to_top(a, pos);
	pb(a, b);
	pos = pos_of(*a, 1);
	bring_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
