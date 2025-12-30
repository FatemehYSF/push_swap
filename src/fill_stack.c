/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:46:40 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:47:00 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Validates tokens, converts them to integers, and fills stack A.
 *
 * Loops through all tokens, checks if they are valid numbers, converts them,
 * checks for duplicates, and adds each number to stack A. Frees tokens at
 * the end. On any error, frees all memory and exits.
 *
 * @param a Pointer to stack A (initially empty).
 * @param tokens Array of numeric string tokens from ft_split.
 */
void	fill_stack(t_node **a, char **tokens)
{
	int	i;
	int	value;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			free_all_and_exit(a, tokens);
		value = safe_atoi(tokens[i], a, tokens);
		if (check_duplicates(*a, value))
			free_all_and_exit(a, tokens);
		add_back(a, new_node(value));
		i++;
	}
	free_tokens(tokens);
}
