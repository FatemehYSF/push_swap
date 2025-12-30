/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 12:31:01 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/* int	main(void)
{
	char	test_chars[]= "aZ3#m";
	int	i = 0;
	char 	esult;

	while (test_chars[i])
	{
		result = ft_isalpha(test_chars[i]) + '0';
		write(1, &test_chars[i], 1);
		write(1, ": ", 2);
		write(1, &result, 1);
		write(1, "\n", 1);
		i++;
	}

	return 0;
} */