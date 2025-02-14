/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:49:44 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:09 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_sorted(t_stack	*stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_highest_node(t_stack *stack)
{
	int			highest;
	t_stack		*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
