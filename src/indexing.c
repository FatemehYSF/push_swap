/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:11:30 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/18 16:29:01 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Copies all values from a stack into a newly allocated array.
 *
 * This function traverses stack A and stores each node's value into an
 * integer array. The order in the array reflects the original order of
 * the stack. The array is used later during the indexing step to sort
 * the values without modifying the stack itself.
 *
 * @param a Pointer to the first node of stack A.
 * @param size The number of elements in the stack.
 *
 * @return A pointer to a newly allocated integer array containing the
 *         stack values, or NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the returned array.
 */
static int	*stack_to_array(t_node *a, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (a)
	{
		array[i] = a->value;
		a = a->next;
		i++;
	}
	return (array);
}

/**
 * @brief Sorts an integer array in ascending order using bubble sort.
 *
 * This function is used during the indexing step to create a sorted
 * reference array. The sorted order allows us to map each stack value
 * to its rank (index) within the full set of values.
 *
 * @param array Pointer to the integer array to sort.
 * @param size Number of elements in the array.
 *
 * @note Sorting is performed in-place; no additional memory is allocated.
 */
static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Finds the index of a value inside a sorted array.
 *
 * @param array Pointer to the sorted integer array.
 * @param size Number of elements in the array.
 * @param value The number to search for.
 *
 * @return The index (rank) of the value inside the array.
 */
static int	find_index_in_array(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Replaces each value in the stack with its index in the sorted order.
 *
 * This function assigns each number in stack A a unique rank (0 = smallest),
 * simplifying the later sorting steps such as radix sort.
 *
 * @param a Pointer to the first node of stack A.
 */
void	index_stack(t_node *a)
{
	int		*array;
	int		size;
	t_node	*current;

	size = stack_size(a);
	array = stack_to_array(a, size);
	if (!array)
		return ;
	sort_array(array, size);
	current = a;
	while (current)
	{
		current->value = find_index_in_array(array, size, current->value);
		current = current->next;
	}
	free(array);
}
