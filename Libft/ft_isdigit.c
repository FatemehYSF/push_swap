/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 13:59:49 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks whether a character is a decimal digi
 * 
 * @param c 
 * @return int Returns a non-zero value if `c` is a digit ('0'–'9'),
 *         otherwise returns 0.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* int main(void)
{
    char test_chars[] = "aZ3#m";
    int i = 0;
    char result;

    while (test_chars[i])
    {
        result = ft_isdigit(test_chars[i]) + '0';
        write(1, &test_chars[i], 1);
        write(1, ": ", 2);
        write(1, &result, 1);
        write(1, "\n", 1);
        i++;
    }

    return 0;
} */