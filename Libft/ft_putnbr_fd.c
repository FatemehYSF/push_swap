/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/28 11:35:08 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes an integer as a string to a file descriptor.
 * 
 * The ft_putnbr_fd function converts the integer `n` to its decimal
 * string representation and writes it to the file descriptor `fd`.
 * Memory for the string is dynamically allocated and freed internally.
 * 
 * @param n The integer to write.
 * @param fd The file descriptor to write to (e.g., 1 for stdout,
 *           2 for stderr).
 * 
 * @return void
 * 
 * @note If memory allocation for the string fails, the function does nothing.
 *       The file descriptor must be valid and open for writing.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &(char){n % 10 + '0'}, 1);
}
/* int main()
{
	int number = 123;
	ft_putnbr_fd(number, 1);
	return (0);
} */