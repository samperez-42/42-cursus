/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:28:34 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:52:11 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Creates a new string result of applying a function through a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res || !s)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
