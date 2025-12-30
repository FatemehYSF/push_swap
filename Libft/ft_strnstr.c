/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:37:32 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates a substring in a string, searching up to a given length.
 * 
 * The ft_strnstr function searches for the first occurrence of the
 * null-terminated string `little` within the string `big`, examining
 * at most `len` characters. The search stops at the first match or
 * when `len` characters have been checked.
 * 
 * @param big Pointer to the null-terminated string to search in.
 * @param little Pointer to the null-terminated substring to search for.
 * @param len Maximum number of characters to examine in `big`.
 * 
 * @return A pointer to the beginning of the located substring in `big`,
 *         or NULL if the substring is not found 
 * 			within the first `len` characters.
 *         If `little` is an empty string, returns `big`.
 * 
 * @note The function does not search beyond the first `len` characters of `big`.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && (i + j) < len && big[i + j] == little[j])
			j ++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i ++;
	}
	return (NULL);
}
/* int main(void)
{
    const char big[] = "Hello, Fatemeh yousefi!";
    const char *little = "Fatemeh";

    char *found = ft_strnstr(big, little, 20);

    if (found)
        printf("Found '%s'!\n in %s", little, found);
    else
        printf("Did not find '%s'.\n", little);

    return 0;
} */
