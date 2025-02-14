/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:00:49 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:44:38 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies memory area
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (dest == 0 && src == 0)
		return (NULL);
	else if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		char_dest = (unsigned char *) dest;
		char_src = (unsigned char *) src;
		i = n;
		while (i > 0)
		{
			char_dest[i - 1] = char_src[i - 1];
			i--;
		}
	}
	return (dest);
}
