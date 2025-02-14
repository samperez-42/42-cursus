/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:58 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 10:26:42 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function moves a node to the top of the stack
// Used for cheapest node and correct position of a
void	do_move(t_stack **a, t_stack *node)
{
	int	index;

	index = 0;
	index = node->index;
	if (node->below == false)
	{
		while (index-- >= 1)
			ra(a);
	}
	else if (node->below == true)
	{
		while (index < stack_size(*a))
		{
			rra(a);
			index++;
		}
	}
}

void	do_move_target(t_stack **b, t_stack *cheapest)
{
	int	index;

	index = 0;
	index = cheapest->target_node->index;
	if (cheapest->target_node->below == false)
	{
		while (index-- >= 1)
			rb(b);
	}
	else if (cheapest->target_node->below == true)
	{
		while (index < stack_size(*b))
		{
			rrb(b);
			index++;
		}
	}
}

// We are using a similar if case for cost_calculations()
void	move_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	set_index(a);
	set_index(b);
	if (cheapest->index != 0)
		do_move(a, cheapest);
	if (cheapest->target_node->index != 0)
		do_move_target(b, cheapest);
}

// Once all nodes are reverse sorted in stack b, we need to move them back to a
// We reuse parts the target_node function for this
void	set_correct_pos(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*a_head;
	int		value;

	target = NULL;
	a_head = *a;
	value = INT_MAX;
	while (*a)
	{
		if ((*a)->nbr <= value && (*a)->nbr > (*b)->nbr)
		{
			value = (*a)->nbr;
			target = *a;
		}
		*a = (*a)->next;
	}
	*a = a_head;
	if (INT_MAX == value)
		target = find_smallest(*a);
	*a = a_head;
	do_move(a, target);
}
