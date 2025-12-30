/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:33:58 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Trims characters from the beginning and end of a string.
 * 
 * The ft_strtrim function returns a new string, which is a copy of `s1`
 * with all characters from the set `set` removed from the start and end
 * of the string. The resulting string is null-terminated and dynamically
 * allocated.
 * 
 * @param s1 Pointer to the null-terminated string to trim.
 * @param set Pointer to a null-terminated string containing characters
 *            to trim from both ends of `s1`.
 * 
 * @return A pointer to the newly allocated trimmed string, or NULL if
 *         memory allocation fails or if `s1` or `set` is NULL.
 * 
 * @note The caller is responsible for freeing the returned string.
 *       The original string `s1` is not modified.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim_str = (char *)malloc(end - start + 1);
	if (!trim_str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trim_str[i] = s1[start];
		start ++;
		i ++;
	}
	trim_str[i] = '\0';
	return (trim_str);
}
/* int main()
{
	char *s1 = "--Fatemeh--";
	char *set = "-";
	printf("%s" , ft_strtrim(s1, set) );
	return 0;
} */