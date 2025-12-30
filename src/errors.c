/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:11:30 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/16 13:20:02 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints an error message and exits the program.
 *
 * This function writes "Error\n" to the standard error output and
 * immediately terminates the program with exit code 1.
 * It does not perform any memory cleanup, so only call it when no
 * dynamic memory needs to be freed.
 */
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Frees an array of strings.
 *
 * This function is used to free the memory allocated for a list of tokens
 * created during argument parsing. It frees each string in the array and
 * then frees the array pointer itself.
 *
 * @param tokens A NULL-terminated array of dynamically allocated strings.
 */
void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * @brief Frees stacks and tokens, prints an error message, and exits.
 *
 * This function safely cleans up all allocated memory related to parsing
 * or stack initialization. It frees the token array (if present), frees
 * the stack 'a', and then prints "Error\n" before terminating the program.
 * It guarantees that no memory leaks occur when exiting due to invalid input.
 *
 * @param a A pointer to the stack pointer that should be freed.
 * @param tokens A NULL-terminated array of strings to free, or NULL.
 */
void	free_all_and_exit(t_node **a, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (a)
		free_stack(a);
	error_exit();
}
