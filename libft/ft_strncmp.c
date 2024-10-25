/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:25 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:52:48 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares 'n' characters of two strings
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
