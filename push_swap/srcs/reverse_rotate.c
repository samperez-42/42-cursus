/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:59 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:37 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Last element becomes the first
static void	reverse_rotate(t_stack **head)
{
	t_stack		*last;
	int			len;

	len = stack_size(*head);
	if (!head || !*head || len == 1)
		return ;
	last = get_last_node(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
