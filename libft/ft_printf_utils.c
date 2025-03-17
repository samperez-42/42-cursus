/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:11:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 14:49:12 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putchar(char c, int *result)
{
	if (*result == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*result = -1;
	else
		*result += 1;
}

void	ft_pf_pointer(unsigned long long ptr, int *result)
{
	if (ptr == 0)
		ft_pf_putstr("(nil)", result);
	else
	{
		ft_pf_putstr("0x", result);
		if (ptr >= 16)
		{
			ft_pf_putnbr_base((ptr / 16), HEXA_LOW, result);
			ft_pf_putnbr_base((ptr % 16), HEXA_LOW, result);
		}
		else
			ft_pf_putnbr_base(ptr, HEXA_LOW, result);
	}
}

void	ft_pf_putnbr_base(long long n, char *base, int *result)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (*result != -1)
	{
		if (n < 0)
		{
			ft_pf_putchar('-', result);
			n = -n;
		}
		if (n > (long long)ft_strlen(base) - 1)
		{
			ft_pf_putnbr_base(n / len_base, base, result);
			ft_pf_putnbr_base(n % len_base, base, result);
		}
		else
			ft_pf_putchar(base[n], result);
	}
}

void	ft_pf_putstr(char *s, int *result)
{
	int	i;

	i = -1;
	if (!s)
		s = "(null)";
	while (s[++i])
		ft_pf_putchar(s[i], result);
}
