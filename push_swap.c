/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatemeh <fatemeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:48:02 by fatemeh           #+#    #+#             */
/*   Updated: 2025/12/19 11:48:04 by fatemeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point of the push_swap program.
 *
 * The program validates and parses the input arguments, builds stack A,
 * normalizes its values using indexing, and then applies the appropriate
 * sorting algorithm. Stack B is used as auxiliary storage. All allocated
 * memory is cleaned up before exiting.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Returns 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*joined;
	char	**tokens;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	joined = join_args(argc, argv);
	if (!joined)
		return (0);
	tokens = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		return (0);
	fill_stack(&a, tokens);
	index_stack(a);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
