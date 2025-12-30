/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/28 10:25:57 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates a string to the end of another with size limit.
 * 
 * The ft_strlcat function appends the null-terminated string `src` to
 * the end of `dst`. It will append at most `dstsize - strlen(dst) - 1`
 * characters, null-terminating the result. The function returns the
 * total length of the string it tried to create, i.e., the initial length
 * of `dst` plus the length of `src`.
 * 
 * @param dst Pointer to the destination buffer. Must be null-terminated.
 * @param src Pointer to the source null-terminated string to append.
 * @param dstsize Total size of the destination buffer including space
 *                for the null terminator.
 * 
 * @return The total length of the string it tried to create: initial length
 *         of `dst` plus length of `src`. If return value >= `dstsize`,
 *         truncation occurred.
 * 
 * @note The function guarantees null-termination if `dstsize` is greater than 0.
 *       Behavior is undefined if `dst` and `src` overlap.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	dst_length = 0;
	src_length = 0;
	i = 0;
	while (dst[dst_length] != '\0')
		dst_length ++;
	while (src[src_length] != '\0')
		src_length ++;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[i] && dst_length + 1 + i < dstsize)
	{
		dst[dst_length + i] = src[i];
		i ++;
	}
	dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}

// int main()
// {
// 	char dst[10] = "Hi";
// 	printf("%zu | %s\n", ft_strlcat(dst, "Fatemeh", 10), dst);
// 	char dst2[6] = "ABC";
// 	printf("%zu | %s\n", ft_strlcat(dst2, "XYZXYZ", 6), dst2);
// 	char dst3[6] = "ABC";
// 	printf("%zu | %s\n", strlcat(dst3, "XYZXYZ", 6), dst3);
// 	char dst4[10] = "Hi";
// 	printf("%zu | %s\n", strlcat(dst4, "Fatemeh", 10), dst);
// 	return 0;
// }