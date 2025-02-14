/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:40:36 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 10:26:24 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// We calculate costs depending on the position of our node and its target node
static void	cost_calculations(t_stack **a, int size_a, int size_b)
{
	if ((*a)->below == false && (*a)->target_node->below == false)
	{
		(*a)->push_cost = 1 + (*a)->index + (*a)->target_node->index;
	}
	else if ((*a)->below == true && (*a)->target_node->below == false)
		(*a)->push_cost = 1 + (size_a - (*a)->index) + (*a)->target_node->index;
	else if ((*a)->below == false && (*a)->target_node->below == true)
		(*a)->push_cost = 1 + (*a)->index + (size_b - (*a)->target_node->index);
	else if ((*a)->below == true && (*a)->target_node->below == true)
	{
		(*a)->push_cost = 1 + (size_a - (*a)->index)
			+ (size_b - (*a)->target_node->index);
	}
}

t_stack	*calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*cheapest;
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	a_head = *a;
	cheapest = *a;
	while (*a)
	{
		cost_calculations(a, size_a, size_b);
		if ((*a)->push_cost < cheapest->push_cost)
			cheapest = *a;
		*a = (*a)->next;
	}
	*a = a_head;
	return (cheapest);
}
