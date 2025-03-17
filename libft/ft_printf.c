/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:24 by samperez          #+#    #+#             */
/*   Updated: 2024/12/04 10:15:27 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_params(char param, va_list args, int *result)
{
	if (param == 'c')
		ft_pf_putchar(va_arg(args, int), result);
	else if (param == 's')
		ft_pf_putstr(va_arg(args, char *), result);
	else if (param == 'p')
		ft_pf_pointer(va_arg(args, unsigned long long), result);
	else if (param == 'd' || param == 'i')
		ft_pf_putnbr_base(va_arg(args, int), DECIMAL, result);
	else if (param == 'u')
		ft_pf_putnbr_base(va_arg(args, unsigned int), DECIMAL, result);
	else if (param == 'x')
		ft_pf_putnbr_base(va_arg(args, unsigned int), HEXA_LOW, result);
	else if (param == 'X')
		ft_pf_putnbr_base(va_arg(args, unsigned int), HEXA_CAP, result);
	else if (param == '%')
		ft_pf_putchar('%', result);
	else
		*result = -1;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_pf_putchar(str[i], &result);
		else if (str[i + 1])
			ft_printf_params(str[++i], args, &result);
		i++;
	}
	va_end(args);
	return (result);
}
