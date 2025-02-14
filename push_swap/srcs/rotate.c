/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:59 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:37:46 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// First element becomes the last
static void	rotate(t_stack **head)
{
	t_stack	*last;
	int		len;

	len = stack_size(*head);
	if (!head || !*head || len == 1)
		return ;
	last = get_last_node(*head);
	last->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
