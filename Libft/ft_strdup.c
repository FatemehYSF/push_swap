/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:05:03 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string by allocating new memory.
 * 
 * The ft_strdup function allocates sufficient memory for a copy of the
 * null-terminated string `s1`, copies the string into the new memory,
 * and returns a pointer to it. The caller is responsible for freeing
 * the allocated memory when no longer needed.
 * 
 * @param s1 Pointer to the null-terminated string to duplicate.
 * 
 * @return A pointer to the newly allocated copy of `s1`, or NULL if
 *         memory allocation fails.
 * 
 * @note The returned string is null-terminated and independent of the
 *       original string.
 */
char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	i = 0;
	str_cpy = malloc ((size + 1) * sizeof(char));
	if (str_cpy == NULL)
		return (NULL);
	while (i < size)
	{
		str_cpy[i] = s1[i];
		i ++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
/* int main()
{
	char *s = "Fatemeh";
	char *s_cpy;

	printf("%s", ft_strdup(s));
	return 0;
} */