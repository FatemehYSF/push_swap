/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 18:46:42 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			word_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word_count);
}

static char	*copy_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	length;
	size_t	i;

	length = end - start;
	word = malloc(length + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **split, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**add_word(char **str_split, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word_i;
	char	*word;

	i = 0;
	word_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			word = copy_word(s, start, i);
			if (!word)
				return (free_split(str_split, word_i), NULL);
			str_split[word_i] = word;
			word_i++;
		}
	}
	str_split[word_i] = NULL;
	return (str_split);
}

/**
 * @brief Splits a string into an array of substrings using a delimiter.
 * 
 * The ft_split function divides the string `s` into substrings separated
 * by the character `c`. Each substring is dynamically allocated and
 * stored in an array of strings, terminated by a NULL pointer.
 * 
 * @param s Pointer to the null-terminated string to split.
 * @param c The delimiter character used to separate words.
 * 
 * @return A NULL-terminated array of strings (substrings), or NULL if
 *         memory allocation fails or if `s` is NULL.
 * 
 * @note The caller is responsible for freeing the memory allocated for
 *       the array and each substring.
 */
char	**ft_split(char const *s, char c)
{
	char	**str_split;

	if (!s)
		return (NULL);
	str_split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str_split)
		return (NULL);
	str_split = add_word(str_split, s, c);
	return (str_split);
}
// int main()
// {
// 	const char *s = "_Hi_Fatemeh__";
// 	char **arr = ft_split(s, '_');

// 	for (int i = 0; arr[i] != NULL; i++)
//     	printf("%s ", arr[i]);
// 	for (int i = 0; arr[i] != NULL; i++)
//     	free(arr[i]);
// 	return (0);
// } 