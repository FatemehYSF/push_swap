/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 17:37:50 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief opies a block of memory from source to destination.
 * 
 * The ft_memcpy function copies `n` bytes from the memory area `src`
 * to the memory area `dst`. The memory areas must not overlap; use
 * ft_memmove if overlapping is possible.
 * 
 * @param dst Pointer to the destination memory area where bytes will be copied.
 * @param src Pointer to the source memory area to copy from.
 * @param n Number of bytes to copy.
 * @return void* Returns a pointer to the destination memory area `dst`.
 * 
 * @warning The behavior is undefined if the source and destination
 *          memory areas overlap.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	s = src;
	d = dst;
	while (n > 0)
	{
		*d = *s;
		d ++;
		s ++;
		n --;
	}
	return (dst);
}
/* int	main()
{
	char src[] = "Hello";
	char dest[20];
	ft_memcpy(dest, src, 3);
	printf("%s", dest);
	return 0;
} */