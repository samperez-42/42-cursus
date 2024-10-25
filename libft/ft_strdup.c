/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:15:55 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:47:43 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicates a string
char	*ft_strdup(const char *s)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(ft_strlen(s) + 1);
	if (res == 0)
		return (NULL);
	while (s[i] != 0)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
