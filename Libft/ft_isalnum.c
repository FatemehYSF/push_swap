/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 11:55:22 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	return ((n >= '0' && n <= '9')
		|| ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')));
}

/* int main(void)
{
    char test_chars[] = "aZ3#m";
    int i = 0;
    char result;

    while (test_chars[i])
    {
        result = ft_isalnum(test_chars[i]) + '0';
        write(1, &test_chars[i], 1);
        write(1, ": ", 2);
        write(1, &result, 1);
        write(1, "\n", 1);
        i++;
    }

    return 0;
} */