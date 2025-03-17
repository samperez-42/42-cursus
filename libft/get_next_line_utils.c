/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:48:57 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 14:48:38 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Duplicates a string
char	*ft_gnl_strdup(char *s)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (free_memory(&res));
	while (s[i] != 0)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// Scans a string for a character
int	ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = len_s1 + len_s2;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return (free_memory((char **)(&s1)));
	i = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		result[i + len_s1] = s2[i];
	result[i + len_s1] = '\0';
	free_memory((char **)(&s1));
	return (result);
}

// This function returns a NULL terminated substring of "s"
char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = (unsigned int)ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_gnl_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub_s = (char *)malloc(sizeof(char) * len + 1);
	if (!sub_s)
		return (free_memory(&sub_s));
	while (i < (unsigned int)len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
