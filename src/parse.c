/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:34:08 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/29 19:46:24 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if a string is a valid integer format.
 * Does this string look like a number?
 *
 * Accepts optional leading '+' or '-' followed by digits.
 * Rejects empty strings, sign-only strings, spaces, and non-digit characters.
 *
 * @param str The string to validate.
 * @return int 1 if valid, 0 otherwise.
 */
int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Safely converts a string to an integer with overflow detection.
 * 
 * This function parses a string representation of a number and converts it to
 * an integer, performing validation and bounds checking. It handles optional
 * leading sign characters ('+' or '-') and ensures the resulting value fits
 * within the range of a 32-bit signed integer (INT_MIN to INT_MAX).
 * 
 * @param str The null-terminated string to convert. Must contain only digits,
 *            optionally preceded by a single '+' or '-' sign character.
 * @param a Pointer to the head of a linked list (t_node) that will be freed
 *          if an error occurs during conversion.
 * @param tokens Array of strings that will be freed if an error occurs during
 *               conversion.
 * 
 * @return The converted integer value if successful.
 * 
 * @note This function will terminate the program via free_all_and_exit() if:
 *       - The string contains any non-digit characters (after an optional sign)
 *       - The resulting value would overflow INT_MAX
 *       - The resulting value would underflow INT_MIN
 * 
 * @warning This function does not return on error; it calls free_all_and_exit()
 *          which terminates the program after cleaning up resources.
 * 
 * @see free_all_and_exit()
 */
int	safe_atoi(char *str, t_node **a, char **tokens)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			free_all_and_exit(a, tokens);
		result = result * 10 + (*str - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			free_all_and_exit(a, tokens);
		str++;
	}
	return ((int)(result * sign));
}

/**
 * @brief Joins all input arguments into a single space-separated string.
 * This function merges all command-line arguments into ONE single string, 
 * separated by spaces.
 *
 * This ensures push_swap can handle inputs like:
 *   ./push_swap 3 2 1
 *   ./push_swap "3 2 1"
 *   ./push_swap "3 2" "1 4"
 * 
 * "3 2 1"
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return char* Newly allocated joined string (must be freed).
 */
char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		error_exit();
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(joined, " ");
		free(joined);
		joined = ft_strjoin(tmp, argv[i]);
		free(tmp);
		i++;
	}
	return (joined);
}

/**
 * @brief Splits the joined argument string into individual tokens.
 *
 * @param joined The space-separated argument string.
 * @return char** A NULL-terminated array of numeric string tokens.
 */
char	**split_tokens(char *joined)
{
	char	**tokens;

	tokens = ft_split(joined, ' ');
	if (!tokens)
		error_exit();
	return (tokens);
}

/**
 * @brief Checks if a value already exists in the stack.
 *
 * @param stack Pointer to the first node of the stack.
 * @param value The integer value to check.
 * @return int Returns 1 if duplicate exists, otherwise 0.
 */
int	check_duplicates(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
