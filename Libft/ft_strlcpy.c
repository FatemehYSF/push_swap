/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:39:02 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies a string to a destination buffer with size limit.
 * 
 * The ft_strlcpy function copies up to `dstsize - 1` characters from
 * the null-terminated string `src` to `dst`, null-terminating the result.
 * It returns the total length of `src`, regardless of the number of
 * characters actually copied.
 * 
 * @param dst Pointer to the destination buffer.
 * @param src Pointer to the source null-terminated string.
 * @param dstsize Size of the destination buffer including space
 *                for the null terminator.
 * 
 * @return The length of `src`. If this value is >= `dstsize`,
 * 			 truncation occurred.
 * 
 * @note The function guarantees null-termination if `dstsize` is greater than 0.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	i = 0;
	src_size = 0;
	while (src[src_size] != '\0')
	{
		src_size ++;
	}
	if (dstsize == 0)
		return (src_size);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	return (src_size);
}
/* int main()
{
    char s[]= "Fatemeh";
    char d[4];
    ft_strlcpy(d, s, 4);
    printf("%s \n", d);
    printf("%zu", ft_strlcpy(d, s, 8));
    return (0);
} */