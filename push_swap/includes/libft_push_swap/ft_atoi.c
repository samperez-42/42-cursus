/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:13:52 by samperez          #+#    #+#             */
/*   Updated: 2024/10/08 16:23:26 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

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

/* int	main(void)
{
	char	*n = "\t\v\f\r\n \f-06050";
	int		i1 = atoi(n);
	int		i2 = ft_atoi(n);

	printf("%d\n", i1);
	printf("%d\n", i2);
} */
