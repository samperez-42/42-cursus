/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:13:45 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:48:02 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies a function to every character of a string
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
