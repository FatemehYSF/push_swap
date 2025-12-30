/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/28 11:28:50 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a specified byte value.
 * 
 * The ft_memset function sets the first `n` bytes of the memory area
 * pointed to by `s` to the byte value `c` (converted to unsigned char).
 * 
 * @param s Pointer to the memory area to fill.
 * @param c The byte value to set (converted to unsigned char).
 * @param n Number of bytes to set.
 * 
 * @return Returns a pointer to the memory area `b`.
 * 
 * @note The function works on raw memory; it does not check for
 *       null-terminated strings.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*start;

	p = (unsigned char *)s;
	start = p;
	while (n > 0)
	{
		*p = c;
		p ++;
		n --;
	}
	return (start);
}

/* int main()
{
    char box[10];
    ft_memset(box, 'A', sizeof(box));
    for (int i = 0; i < 10; i++) {
        printf("%c ", box[i]);
    }
    return 0;
} */