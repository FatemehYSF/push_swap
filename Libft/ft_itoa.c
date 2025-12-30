/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 17:37:15 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Counts the number of digits needed to represent an integer.
 * 
 * The count_digits function calculates how many characters are needed
 * to represent the integer `n` as a string, including the sign for
 * negative numbers and the '0' character for zero.
 * 
 * @param n The integer whose digits are counted.
 * @return int The number of characters required to represent `n` as a string.
 */
static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

static void	fill_num(char *array, unsigned int number, int *count)
{
	while (number > 0)
	{
		array[--(*count)] = (number % 10) + '0';
		number /= 10;
	}
}

/**
 * @brief Converts an integer to a null-terminated string.
 * 
 * The ft_itoa function allocates and returns a string representing
 * the integer `n` in decimal (base 10). The returned string is
 * null-terminated and must be freed by the caller when no longer needed.
 * 
 * @param n The integer to convert.
 * @return char*  pointer to the allocated string representing `n`, or NULL
 *         if memory allocation fails.
 * @note - Handles zero and negative integers correctly.
 * - The caller is responsible for freeing the returned string.
 */
char	*ft_itoa(int n)
{
	int				count;
	char			*array;
	unsigned int	number;

	count = count_digits(n);
	array = malloc (sizeof(char) * (count + 1));
	if (!array)
		return (NULL);
	array[count] = '\0';
	if (n == 0)
	{
		array[0] = '0';
		return (array);
	}
	if (n < 0)
	{
		array[0] = '-';
		number = -n;
	}
	else
		number = n;
	fill_num(array, number, &count);
	return (array);
}
/* int main()
{
	int n = 123;
	printf("%s", ft_itoa(n));
	return (0);
} */