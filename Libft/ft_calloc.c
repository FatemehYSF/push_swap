/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/10/28 11:04:27 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
/**
 * @brief Allocates memory for an array and initializes it to zero.
 * 
 * The ft_calloc function allocates memory for an array of `count` elements,
 * each of size `size` bytes, and initializes all bytes in the allocated
 * memory to zero. It is equivalent to calling malloc followed by memset
 * to zero.
 * 
 * @param count Number of elements to allocate.
 * @param size Size in bytes of each element.
 * 
 * @warning  * - If `count` or `size` is zero,
 *  behavior depends on the implementation of malloc; 
 *   it may return NULL or a unique pointer
 * 	 that should not be dereferenced.
 * - If the multiplication `count * size` would overflow `size_t`, the function 
 *   returns NULL to prevent undefined behavior.
 * - Always check the return value before using the allocated memory.
 * 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	if (size && count > __SIZE_MAX__ / size)
		return (NULL);
	total = count * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, total);
	return (mem);
}
/* int main(void)
{
    int *arr = ft_calloc(5, sizeof(int));
    if (!arr)
    {
        printf("Allocation failed!\n");
        return 1;
    }
    for (size_t i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);

    return 0;
} */