/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:16:28 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:39:46 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Selects the appropriate sorting algorithm based on stack size.
 *
 * For very small stacks (2–5 elements), specialized sorting functions
 * are used because they require fewer operations. For larger stacks,
 * a binary radix sort is applied. If the stack is already sorted,
 * the function immediately returns.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B (used as auxiliary storage).
 */
void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
