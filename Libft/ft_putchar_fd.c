/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/27 14:45:57 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a single character to a file descriptor.
 * 
 * The ft_putchar_fd function outputs the character `c` to the file
 * descriptor specified by `fd`. This can be used to write to standard
 * output, standard error, or any open file descriptor.
 * 
 * @param c The character to write.
 * @param fd The file descriptor to write to (e.g., 1 for stdout,
 *           2 for stderr).
 * 
 * @return void
 * 
 * @note The function writes exactly one byte. The file descriptor
 *       must be valid and open for writing.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* int main()
{
	//ft_putchar_fd('A', 1);
	ft_putchar_fd('E', 2);
	return 0;
} */