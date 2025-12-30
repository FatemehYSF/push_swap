/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 14:56:22 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string followed by a newline to a file descriptor.
 * 
 * The ft_putendl_fd function outputs the string `s` to the file
 * descriptor `fd`, followed by a newline character (`\n`). If `s`
 * is NULL, the function does nothing.
 * 
 * @param s Pointer to the null-terminated string to write.
 * @param fd The file descriptor to write to (e.g., 1 for stdout,
 *           2 for stderr).
 * 
 * @return void
 * 
 * @note The function writes each character of the string individually
 *       and then appends a newline. The file descriptor must be valid
 *       and open for writing.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s ++;
	}
	write(fd, "\n", 1);
}
/* int main()
{
	ft_putendl_fd("Fatemeh", 1);
	return (0);

} */