/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 17:00:37 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Extracts a substring from a string.
 * 
 * The ft_substr function returns a newly allocated string containing
 * up to `len` characters from the string `s`, starting at index `start`.
 * If `start` is greater than the length of `s`, an empty string is returned.
 * The resulting string is null-terminated.
 * 
 * @param s Pointer to the null-terminated string to extract from.
 * @param start The starting index in `s` from which to begin extraction.
 * @param len Maximum number of characters to include in the substring.
 * 
 * @return A pointer to the newly allocated substring, or NULL if memory
 *         allocation fails or if `s` is NULL.
 * 
 * @note The caller is responsible for freeing the returned string.
 *       The original string `s` is not modified.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/* int main(void)
{
    char *s = "Hello, Fatemeh!";
    char *sub;

    sub = ft_substr(s, 7, 5);
    if (sub)
    {
        printf("%s\n", sub);
        free(sub);
    }

    return 0;
} */