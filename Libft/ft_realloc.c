/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:15 by carzhang          #+#    #+#             */
/*   Updated: 2025/04/02 13:53:47 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
// {
// 	void	*new_ptr;

// 	if (new_size == 0 && ptr)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// 	if (!ptr)
// 		return (malloc(new_size));
// 	new_ptr = malloc(new_size);
// 	if (!new_ptr)
// 		return (NULL);
// 	if (new_size > old_size)
// 		ft_memcpy(new_ptr, ptr, old_size);
// 	else
// 		ft_memcpy(new_ptr, ptr, new_size);
// 	free(ptr);
// 	return (new_ptr);
// }


void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (new_size > old_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
    ft_bzero((char *)new_ptr + old_size, new_size - old_size);
	
	return (new_ptr);
}



// void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
// {
//     void *new_ptr = malloc(new_size);
//     if (!new_ptr)
//         return NULL;
//     if (ptr)
//     {
//         ft_memcpy(new_ptr, ptr, old_size);
//         free(ptr);
//     }
//     // Initialiser la mémoire supplémentaire à NULL
//     ft_bzero((char *)new_ptr + old_size, new_size - old_size);
//     return new_ptr;
// }
