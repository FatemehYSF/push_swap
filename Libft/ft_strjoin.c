/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:04:56 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string.
 * 
 * The ft_strjoin function allocates memory for a new string that
 * contains the contents of `s1` followed by the contents of `s2`.
 * The resulting string is null-terminated and must be freed by the caller.
 * 
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * 
 * @return Pointer to the newly allocated concatenated string, or NULL
 *         if memory allocation fails or if `s1` or `s2` is NULL.
 * 
 * @note The original strings `s1` and `s2` are not modified.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	join_len;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	join_len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(join_len + 1);
	if (!join_str)
		return (NULL);
	temp = join_str;
	ft_memcpy(temp, s1, ft_strlen(s1));
	temp += ft_strlen(s1);
	ft_memcpy(temp, s2, ft_strlen(s2));
	join_str[join_len] = '\0';
	return (join_str);
}
/* int main()
{
	char *s1 = "Fatemeh";
	char *s2 = "Yousefi";
	char *join_str = ft_strjoin(s1, s2);
	printf("%s\n", join_str);
	free(join_str);
	return 0;
} */