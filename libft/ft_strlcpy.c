/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:59:44 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:50:53 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies up to 'size' - 1 characters from src to dst
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	src_len;
	size_t	dst_limit;

	src_len = ft_strlen(src);
	length = src_len;
	if (!src)
	{
		if (dst && 0 < size)
			dst[0] = 0;
		return (src_len);
	}
	if (!dst || size == 0)
		return (src_len);
	dst_limit = size - 1;
	if (dst_limit < length)
		length = dst_limit;
	ft_memcpy(dst, src, length);
	dst[length] = '\0';
	return (src_len);
}
