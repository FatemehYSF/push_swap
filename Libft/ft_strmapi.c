/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 15:38:32 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Applies a function to each character of a string,
 *  creating a new string.
 * 
 * The ft_strmapi function iterates over the null-terminated string `s`
 * and applies the function `f` to each character. The function `f`
 * receives the index of the character and the character itself, and
 * returns a new character. The resulting characters are stored in a
 * newly allocated string.
 * 
 * @param s Pointer to the null-terminated string to process.
 * @param f Function pointer to apply to each character.
 *  		It takes the
 *          character's index and the character, 
 * 			and returns a modified character.
 * 
 * @return A pointer to the newly allocated string with modified characters,
 *         or NULL if `s` or `f` is NULL, or if memory allocation fails.
 * 
 * @note The caller is responsible for freeing the returned string.
 *       The original string `s` is not modified.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	result_str = malloc(sizeof(char) * (i + 1));
	if (!result_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result_str[i] = f(i, s[i]);
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}
/* char f(unsigned int i, char c)
{
	return i + c;
}
int main()
{
	char *s = "abcd";
	char *result = ft_strmapi(s,f);
	printf("%s", result);
	free(result);
	return (0);
} */