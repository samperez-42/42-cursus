/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:08:16 by samperez          #+#    #+#             */
/*   Updated: 2025/01/07 13:10:44 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_before(const char *nptr, int *i, int *neg)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	if (nptr[*i] == '+')
	{
		(*i)++;
	}
	else if (nptr[*i] == '-')
	{
		(*i)++;
		(*neg)++;
	}
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 0;
	res = 0;
	if (nptr[i] == 0)
		return (0);
	check_before(nptr, &i, &neg);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}
