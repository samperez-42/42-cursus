/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:31:46 by samperez          #+#    #+#             */
/*   Updated: 2024/10/21 18:24:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Frees memory in the heap
static void	*free_mem(char **res, int j)
{
	while (--j >= 0)
	{
		free(res[j]);
	}
	free(res);
	return (NULL);
}

// Counts the number of substrings needed for the malloc
static int	how_many(char const *s, char c)
{
	int	i;
	int	len;
	int	word_check;

	i = 0;
	len = 0;
	word_check = 0;
	while (s[i])
	{
		if (s[i] != c && word_check == 0)
		{
			word_check = 1;
			len++;
		}
		else if (s[i] == c)
			word_check = 0;
		i++;
	}
	return (len);
}

// Updates the position of start & end for the substrings
static void	update_start_end(char const *s, char c, int *start, int *end)
{
	while (s[*start] == c)
	{
		*start += 1;
	}
	*end = *start;
	while (s[*end] && s[*end] != c)
	{
		*end += 1;
	}
}

// Splits a string into substrings divided by a separator char
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		start;
	int		end;
	int		j;

	res = (char **)malloc(sizeof(char *) * (how_many(s, c) + 1));
	if (!res || !s)
		return (NULL);
	start = 0;
	end = 0;
	j = 0;
	while (s[start])
	{
		update_start_end(s, c, &start, &end);
		if (start < end || s[end] == c)
		{
			res[j] = ft_substr(s, start, end - start);
			if (!res[j])
				return (free_mem(res, j), NULL);
			start = end;
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
