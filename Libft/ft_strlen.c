/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:48 by cylini            #+#    #+#             */
/*   Updated: 2025/04/16 03:00:44 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	str[] = "123";
	size_t	len;

	len = ft_strlen(str);
	printf("la longueur de la chaine est de %zd\n",len);
	return (0);
}*/
