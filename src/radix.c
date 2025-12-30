/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:29:25 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:12:14 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts stack A using binary radix sort on indexed values.
 *
 * For each bit position (from least to most significant), all elements
 * are examined once:
 *
 *  - ((*a)->value)     : value at the top of stack A
 *  - value >> i        : shifts the bit we want to check into the last position
 *  - (value >> i) & 1  : checks whether that bit is 0 or 1
 *
 * If the bit is 0, the value is pushed to stack B (pb).  
 * If the bit is 1, it stays in stack A and we rotate (ra).
 * After the pass, all values from B are pushed back to A (pa).
 *
 * The number of required bit passes is determined by:
 *      while ((size - 1) >> max_bits) max_bits++;
 * This counts how many bits are needed to represent the largest index.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B (temporary storage).
 */
void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*a)->value) >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
