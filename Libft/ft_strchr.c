/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:01:13 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the first occurrence of a character in a string.
 * 
 * The ft_strchr function scans the string `s` for the first occurrence
 * of the character `c` (converted to unsigned char). The terminating
 * null byte `\0` is considered part of the string.
 * 
 * @param s Pointer to the null-terminated string to search.
 * @param c The character to locate (converted to unsigned char).
 * 
 * @return A pointer to the first occurrence of `c` in the string,
 *         or NULL if the character is not found.
 * 
 * @note The function includes the null terminator in the search, so
 *       searching for '\0' will return a pointer to the string's end.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// int main()
// {
// 	char s[7] = "Fatemeh";
// 	printf("%s", ft_strchr(s , 'a'));
// }