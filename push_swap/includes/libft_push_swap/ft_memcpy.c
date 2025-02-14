/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:00:36 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:43:52 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies memory area
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (dest == 0 && src == 0)
		return (0);
	char_dest = (unsigned char *) dest;
	char_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
