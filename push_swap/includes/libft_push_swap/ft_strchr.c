/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:12:59 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:47:29 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Scans a string for a character
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i])
	{
		if (*s == (char)c)
			return (&((char *)s)[i]);
		s++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}
