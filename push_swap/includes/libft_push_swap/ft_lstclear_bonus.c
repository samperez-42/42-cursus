/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:26:38 by samperez          #+#    #+#             */
/*   Updated: 2024/10/10 17:56:24 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	else
	{
		tmp = *lst;
		while (tmp)
		{
			*lst = tmp->next;
			(*del)(tmp->content);
			free(tmp);
			tmp = *lst;
		}
	}
}
