/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 16:35:17 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

/**
 * @brief Converts a string to an integer.
 * 
 * The ft_atoi function converts the initial portion of the string
 * pointed to by `nptr` to its corresponding integer value.
 * It ignores any leading whitespace characters, recognizes an
 * optional '+' or '-' sign, and then processes consecutive digit
 * characters until a non-digit is encountered.
 * 
 * 
 * @param nptr nptr Pointer to the string to be converted.
 * 
 *  * @warning 
 * - The function does not handle integer overflow or underflow; 
 *   behavior is undefined if the result exceeds the range of `int`.
 * - Only the characters up to the first non-digit (after optional sign)
 *   are processed.
 * 
 * @return int 
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;
	int	digit;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}
/* int main(void)
{
    const char *tests[] = {
        "42",
        "   123",
        "   -42",
        "+99",
        "--56",
        "  +00123abc",
        "abc123",
        "   -0000042",
        "",
        "   +0",
        NULL
    };

    int i = 0;
    while (tests[i])
    {
        printf("Input: \"%s\"  , Output: %d\n", tests[i], ft_atoi(tests[i]));
        i++;
    }

    return 0;
} */