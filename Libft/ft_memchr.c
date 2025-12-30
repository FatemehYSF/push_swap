/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 14:37:47 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Searches for a byte in a block of memory.
 * 
 * The ft_memchr function scans the first `n` bytes of the memory area
 * pointed to by `s` for the first occurrence of the byte `c`. The search
 * stops as soon as the byte is found or `n` bytes have been scanned.
 * 
 * @param s Pointer to the memory area to search.
 * @param c The byte value to search for (converted to unsigned char).
 * @param n Number of bytes to examine.
 * @return void* A pointer to the first occurrence of the byte `c` within
 *         the memory block, or NULL if the byte is not found in the
 *         first `n` bytes.
 * 
 * @note The function does not check for null-terminated strings; it
 *       works purely on raw memory blocks.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i ++;
	}
	return (NULL);
}
/* int main()
{
	char mem[] = {'F', 'a', 't', 'e', 'm', 'e', 'h', '\0', 'x'};
	char *s = ft_memchr(mem, 'e', 9);
	if (s)
		printf("Found: %c\n", *s);
	printf("%s" , s);
	return 0;
} */