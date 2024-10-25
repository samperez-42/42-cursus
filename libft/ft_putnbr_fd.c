/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:00:22 by samperez          #+#    #+#             */
/*   Updated: 2024/10/04 11:45:06 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function is capable of writing the total range of an int
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}
