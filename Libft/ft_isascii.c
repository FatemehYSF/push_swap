/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 13:55:56 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks whether a character is an ASCII character
 * 
 * ASCII codes range from 0 to 127.
 * 
 * @param c The integer value to check.
 * @return int Returns a non-zero value if `c` is an ASCII character (0–127),
 *         otherwise returns 0.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int main(void)
{
    char test_chars[] = "aZ3#m你好";
    int i = 0;
    char result;

    while (test_chars[i])
    {
        result = ft_isascii(test_chars[i]) + '0';
        write(1, &test_chars[i], 1);
        write(1, ": ", 2);
        write(1, &result, 1);
        write(1, "\n", 1);
        i++;
    }

    return 0;
} */