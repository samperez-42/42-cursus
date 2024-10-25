/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:54 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:50:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenates 'size' - 1 characters of src into dst
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dst[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
