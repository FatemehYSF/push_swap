/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:33:16 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Searches for the last occurrence of a character in a string.
 * 
 * The ft_strrchr function scans the null-terminated string `s` for the
 * last occurrence of the character `c` (converted to unsigned char).
 * The terminating null byte `\0` is considered part of the string.
 * 
 * @param s Pointer to the null-terminated string to search.
 * @param c The character to locate (converted to unsigned char).
 * 
 * @return A pointer to the last occurrence of `c` in the string, or
 *         NULL if the character is not found. If `c` is `\0`, returns
 *         a pointer to the string's null terminator.
 * 
 * @note The function searches the entire string and includes the null
 *       terminator in the search.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			j = i;
		i ++;
	}
	if (j >= 0)
		return ((char *)&s[j]);
	else if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

// int main()
// {
// 	char s[] = "Fatemeh";
// 	printf("%s\n", ft_strrchr(s, 'e'));
// printf("%s\n", ft_strrchr(s, 'F'));
// printf("%s\n", ft_strrchr(s, 'z'));
// printf("%s\n", ft_strrchr(s, '\0'));
// 	return 0;
// }