/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:53:20 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 13:57:50 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
		new->next = *lst;
	*lst = new;
}
