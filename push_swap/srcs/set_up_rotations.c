/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:09:24 by samperez          #+#    #+#             */
/*   Updated: 2025/02/11 15:14:20 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_up_b(t_stack **b)
{
	t_stack		*highest;
	int			index;

	highest = return_highest_node(*b);
	index = 0;
	index = highest->index;
	if (highest->below == false)
	{
		while (index-- >= 1)
			rb(b);
	}
	else if (highest->below == true)
	{
		while (index < stack_size(*b))
		{
			rrb(b);
			index++;
		}
	}
}

void	check_rotation(t_stack **a)
{
	t_stack	*smallest;

	smallest = NULL;
	if (!stack_sorted(*a))
	{
		smallest = find_smallest(*a);
		do_move(a, smallest);
	}
}
