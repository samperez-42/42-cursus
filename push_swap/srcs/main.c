/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:50:00 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 10:30:21 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = a;
	printf("\nStack a\n");
	while (a)
	{
		printf("Number in stack a: %d  Position: %d", a->nbr, a->index);
		a = a->next;
		printf("\n");
	}
	if (b)
	{
		printf("\nStack b\n");
		head_b = b;
		while (b)
		{
			printf("Number in stack b: %d Position: %d\n", b->nbr, b->index);
			b = b->next;
		}
		b = head_b;
	}
	a = head_a;
	printf("\n");
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_ps_split(argv[1], ' ');
	if (!argv)
		return (0);
	init_stack(&a, argv + 1, 2 == argc);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
