/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:47:50 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:55:34 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	This function searches for the substring of s1 that doesnt appear in set.
//	Then, it returns the new string result from removing set from s1 
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		start;
	int		end;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1)
		start++;
	end = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[end]))
		end--;
	trimmed_str = ft_substr(s1, start, end - start + 1);
	return (trimmed_str);
}
