/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:21:23 by samperez          #+#    #+#             */
/*   Updated: 2025/02/07 10:51:26 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stack **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (argc_2 == true)
		free_argv(argv);
}
