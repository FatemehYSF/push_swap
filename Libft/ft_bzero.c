/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:39:52 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Sets a block of memory to zero.
 * 
 * Sets the first `n` bytes of the memory pointed to by `s` to `0`.
 * 
 *
 * @param s Pointer to the memory area to be zeroed.
 * @param n Number of bytes to set to zero.
 * 
 * @warning  Make sure `s` points to a valid memory 
 * 				region with at least `n` bytes.
 * 
 * @return void
 * 
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p ++;
		n --;
	}
}

/* int main()
{
    char box[10];
    ft_bzero(box, sizeof(box));
    for (int i = 0; i < 10; i++) {
        printf("%c ", box[i]);
    }
    return 0;
} */