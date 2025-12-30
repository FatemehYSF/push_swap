/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:30:10 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Calculates the length of a null-terminated string.
 * 
 * The ft_strlen function computes the number of characters in the
 * string `str`, excluding the terminating null byte (`\0`).
 * 
 * @param str Pointer to the null-terminated string.
 * 
 * @return The number of characters in the string `str`, not including
 *         the null terminator.
 * 
 * @note The input string must be null-terminated; behavior is undefined
 *       if `str` is NULL.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int main(void)
{
	char *s = "Fatemeh";
	int strlen = ft_strlen(s) + '0';
	write(1, &strlen, 1);	
	
	return 0;
} */