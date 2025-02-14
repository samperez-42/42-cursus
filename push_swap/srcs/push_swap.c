/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:14 by samperez          #+#    #+#             */
/*   Updated: 2025/02/11 15:29:52 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	- Now that all elements in b are sorted, we need to check if they are being
	  pushed in the correct position. If not, we need to rotate the stack a
*/

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	pb(b, a);
	pb(b, a);
	while (stack_size(*a) > 3)
	{
		set_index(a);
		set_index(b);
		set_target_nodes(a, b);
		cheapest = calculate_cost(a, b);
		move_nodes(a, b, cheapest);
		pb(b, a);
	}
	tiny_sort(a);
	set_index(b);
	set_up_b(b);
	while (stack_size(*b) > 0)
	{
		set_index(a);
		set_index(b);
		set_correct_pos(a, b);
		pa(a, b);
	}
	check_rotation(a);
}
