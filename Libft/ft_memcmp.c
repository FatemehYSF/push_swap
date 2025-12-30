/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 14:39:32 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Compares two blocks of memory.
 * 
 * The ft_memcmp function compares the first `n` bytes of the memory areas
 * `s1` and `s2`. The comparison is done byte by byte using unsigned characters.
 * 
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n Number of bytes to compare.
 * @return int An integer less than, equal to, or greater than zero if the first 
 *         differing byte in `s1` is found to be less than, equal to, or 
 *         greater than the corresponding byte in `s2`.
 *         Returns 0 if the first `n` bytes are identical.
 * 
 * @note The function does not stop at null bytes; it compares raw memory
 *       and is suitable for any data type.
 */
int	ft_memcmp(const	void *s1, const	void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int main(void) {
    char a[] = {0x01, 0x02, 0x03};
    char b[] = {0x01, 0x02, 0x03};

    int result = ft_memcmp(a, b, sizeof(a));

    if (result < 0)
        printf("a < b\n");
    else if (result > 0)
        printf("a > b\n");
    else
        printf("a = b\n");

    return 0;
}
 */