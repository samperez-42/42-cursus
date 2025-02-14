/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:02:35 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:53:44 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Scans a string for a substring
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	swp;

	i = 0;
	if (!(little[0]))
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		swp = i;
		while (big[i] == little[j] && big[i] && i < len)
		{
			j++;
			i++;
		}
		if (little[j] == 0)
			return ((char *)&big[swp]);
		i = swp + 1;
	}
	return (NULL);
}

/*
int    main(void)
{
    char    little[] = "hola";
    char    big[] = "Samuel hola";
    char    *own_ptr;

    own_ptr = ft_strnstr(big, little, 11);
}
*/
