/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:25:21 by samperez          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:45 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function returns a NULL terminated substring of "s"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = (unsigned int)ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (i < (unsigned int)len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
