/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:26:08 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:30 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int			i;
	t_stack		*tmp;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*find_smallest(t_stack *head)
{
	t_stack	*smallest;

	smallest = head;
	if (NULL == head)
		return (NULL);
	while (head->next)
	{
		if (head->nbr < smallest->nbr)
			smallest = head;
		head = head->next;
	}
	if (head->nbr < smallest->nbr)
		smallest = head;
	return (smallest);
}

t_stack	*return_highest_node(t_stack *head)
{
	t_stack	*highest;

	highest = head;
	if (NULL == head)
		return (NULL);
	while (head->next)
	{
		if (head->nbr > highest->nbr)
			highest = head;
		head = head->next;
	}
	if (head->nbr > highest->nbr)
		highest = head;
	return (highest);
}

t_stack	*get_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack **a, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (NULL == a)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (NULL == *a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}
