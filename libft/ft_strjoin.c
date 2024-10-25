/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:22:32 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:48:41 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Creates a NULL terminated new string from the concatenation of s1 and s2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}
