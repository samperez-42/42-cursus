/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:54 by samperez          #+#    #+#             */
/*   Updated: 2025/02/11 15:14:11 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_target_node(t_stack **a, t_stack **b)
{
	t_stack	*target_node;
	t_stack	*b_head;
	int		value;

	value = INT_MIN;
	b_head = *b;
	target_node = NULL;
	while (*b)
	{
		if ((*b)->nbr >= value && (*b)->nbr < (*a)->nbr)
		{
			target_node = *b;
			value = (*b)->nbr;
		}
		*b = (*b)->next;
	}
	if (INT_MIN == value)
	{
		*b = b_head;
		(*a)->target_node = return_highest_node(*b);
	}
	else
		(*a)->target_node = target_node;
	*b = b_head;
}

void	set_target_nodes(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = *a;
	b_head = *b;
	while (*a)
	{
		find_target_node(a, b);
		*a = (*a)->next;
	}
	*a = a_head;
	*b = b_head;
}

void	set_index(t_stack **stack)
{
	int		pos;
	int		size;
	int		half;
	t_stack	*current;

	pos = 0;
	size = stack_size(*stack);
	current = *stack;
	half = (size) / 2;
	while (current)
	{
		current->index = pos;
		if (pos < half)
			current->below = false;
		else
			current->below = true;
		pos++;
		current = current->next;
	}
}
