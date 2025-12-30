/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:32:24 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Compares up to n characters of two strings.
 * 
 * The ft_strncmp function compares the first `n` characters of the
 * null-terminated strings `s1` and `s2`. Comparison is done using
 * unsigned characters.
 * 
 * @param s1 Pointer to the first string to compare.
 * @param s2 Pointer to the second string to compare.
 * @param n Maximum number of characters to compare.
 * 
 * @return An integer less than, equal to, or greater than zero if the
 *         first differing character in `s1` is found to be less than,
 *         equal to, or greater than the corresponding character in `s2`.
 *         Returns 0 if the first `n` characters are identical or if n is 0.
 * 
 * @note The function does not compare beyond the first null terminator
 *       of either string.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0'
		&& i < n && ((unsigned char)s1[i] == (unsigned char)s2[i]))
	{
		i ++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <string.h>

int main()
{
	printf("%d\n" , ft_strncmp("test\200", "test\0", 6));
	printf("%d\n" , strncmp("test\200", "test\0", 6));
	return 0;
} */