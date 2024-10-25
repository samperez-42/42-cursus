/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:50:43 by samperez          #+#    #+#             */
/*   Updated: 2024/10/04 14:17:06 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = malloc(nmemb * size);
	if (arr == 0)
		return (NULL);
	while (i < nmemb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
