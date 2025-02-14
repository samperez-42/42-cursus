/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:31:08 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:46:22 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sends the string into the designed file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
