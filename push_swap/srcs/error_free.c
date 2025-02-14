/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:16 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:36:19 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Frees the argv in case it is dynamically allocated
void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

// Frees the stack
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Checks non numeric characters
int	error_syntax(char	*argv)
{
	int		i;

	i = 0;
	if (argv[0] == '-')
	{
		i++;
	}
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

// Checks repeating values
int	error_repetition(t_stack *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

/* Frees the stack (and the argv in case it's allocated) 
and terminates the program */
void	error_free(t_stack **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2 == true)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}
