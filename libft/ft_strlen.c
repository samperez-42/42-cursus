/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:19:07 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:51:07 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Measures the length of a string
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
