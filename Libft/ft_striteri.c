/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:04:59 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string with its index.
 * 
 * The ft_striteri function iterates over the null-terminated string `s`
 * and applies the function `f` to each character. The function `f` receives
 * the index of the character and a pointer to the character itself,
 * allowing in-place modification.
 * 
 * @param s Pointer to the null-terminated string to iterate over.
 * @param f Function pointer to apply to each character. It takes the
 *          character's index and a pointer to the character.
 * 
 * @return void
 * 
 * @note If `s` or `f` is NULL, the function does nothing.
 *       The function allows modification of the original string in-place.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
    char str[] = "fatemeh";
    ft_striteri(str, to_upper);
    printf("%s\n", str);
    return 0;
} */