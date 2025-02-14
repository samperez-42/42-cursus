/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:06 by samperez          #+#    #+#             */
/*   Updated: 2025/02/10 12:56:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		*dest = node_to_push;
		(*dest)->next->prev = *dest;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
