/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:50:08 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 18:40:40 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	//Same as memset, just with null characters
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
