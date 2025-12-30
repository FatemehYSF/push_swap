/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 14:58:12 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string to a file descriptor.
 * 
 * The ft_putstr_fd function outputs the null-terminated string `s`
 * to the file descriptor `fd`. If `s` is NULL, the function does nothing.
 * 
 * @param s Pointer to the string to write.
 * @param fd The file descriptor to write to (e.g., 1 for stdout,
 *           2 for stderr).
 * 
 * @return void
 * 
 * @note The function writes each character of the string individually.
 *       The file descriptor must be valid and open for writing.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s ++;
	}
}
/* int main()
{
	ft_putstr_fd("Fatemeh", 1);
	return (0);

} */