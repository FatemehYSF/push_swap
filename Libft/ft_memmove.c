/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:39:37 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies memory forwards (helper function for ft_memmove).
 * 
 * Copies `len` bytes from `s` to `d` in ascending order.
 * Used when the destination is before the source in memory.
 * 
 * @param d Destination pointer.
 * @param s Source pointer.
 * @param len Number of bytes to copy.
 */
static void	memmove_forward(
	unsigned char *d, const unsigned char *s, size_t len
)
{
	while (len--)
		*d++ = *s++;
}

/**
 * @brief Copies memory backwards (helper function for ft_memmove).
 * 
 * Copies `len` bytes from `s` to `d` in descending order.
 * Used when the destination is after the source in memory.
 * 
 * @param d Destination pointer.
 * @param s Source pointer.
 * @param len Number of bytes to copy.
 */
static void	memmove_backward(
	unsigned char *d, const unsigned char *s, size_t len)
{
	d += len - 1;
	s += len - 1;
	while (len--)
		*d-- = *s--;
}

/**
 * @brief Copies a block of memory, safely handling overlapping regions.
 * 
 * The ft_memmove function copies `len` bytes from the memory area `src`
 * to the memory area `dst`. Unlike ft_memcpy, it correctly handles
 * overlapping source and destination regions by determining the copy
 * direction.
 * 
 * @param dst Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param len Number of bytes to copy.
 * 
 * @return Returns a pointer to the destination memory area `dst`.
 * 
 * @note The function automatically chooses whether to copy bytes
 *       forwards or backwards depending on the relative positions
 *       of `src` and `dst` to prevent data corruption.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	if (d < s)
		memmove_forward(d, s, len);
	else
		memmove_backward(d, s, len);
	return (dst);
}
/* int main()
{
	char str2[] = "123456";
	ft_memmove(str2, str2 + 2, 4);
	printf("%s\n", str2);

	char str1[] = "abcdef";
	ft_memmove(str1 + 2, str1, 4);
	printf("%s\n", str1);

    return (0);
} */