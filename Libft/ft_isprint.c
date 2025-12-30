/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/09 11:48:56 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int main(void)
{
    char test_chars[] = "aZ3#m\a";
    int i = 0;
    char result;

    while (test_chars[i])
    {
        result = ft_isprint(test_chars[i]) + '0';
        write(1, &test_chars[i], 1);
        write(1, ": ", 2);
        write(1, &result, 1);
        write(1, "\n", 1);
        i++;
    }

    return 0;
} */