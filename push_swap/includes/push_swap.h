/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:56 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 10:31:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft_push_swap/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				below;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack;

// Used for handling both types of inputs (1 2 3 & "1 2 3")
char			**ft_ps_split(char const *s, char c);
// Array to long conversion (used in split)
long			ft_atol(const char *nptr);

/* Sorting functions */

bool			stack_sorted(t_stack *stack);
// Three number sorting algorithm - 2 moves MAX
void			tiny_sort(t_stack **a);
// Cost based algorithm
void			push_swap(t_stack **a, t_stack **b);
// Calculates the push cost of each node
t_stack			*calculate_cost(t_stack **a, t_stack **b);
// Moves the cheapest node on stack a and its target node in stack b to the top
void			move_nodes(t_stack **a, t_stack **b, t_stack *cheapest);
// These two functions move the cheapest node and its target node to the top
void			do_move(t_stack **a, t_stack *node);
void			do_move_target(t_stack **b, t_stack *cheapest);
// Sets a target node in stack b for every node in stack a
void			set_target_nodes(t_stack **a, t_stack **b);
// Once stack b is sorted, this function ra's to the correct pos for b to push
void			set_correct_pos(t_stack **a, t_stack **b);
/*
	Once stack a is sorted, this function rotates or reverse rotates a 
	to get the smallest node to the top of the stack
*/
void			check_rotation(t_stack **a);
/* 
	This function ensures the highest node is at the top of b 
	to begin pushing back to a
*/
void			set_up_b(t_stack **b);

/* Error / Free */

// Frees the argv in case it is dynamically allocated
void			free_argv(char **argv);
// Frees the desired stack
void			free_stack(t_stack **stack);
// Checks non numeric characters
int				error_syntax(char *argv);
// Checks repeating values
int				error_repetition(t_stack *a, int nbr);
// Frees the stack (and the argv in case it's allocated) and returns "Error\n"
void			error_free(t_stack **a, char **argv, bool argc_2);

/* Stack functions */

// Checks every single item in the stack before initializing itself
void			init_stack(t_stack **a, char **argv, bool argc_2);
// Returns the number of elements in the stack
int				stack_size(t_stack *stack);
// Returns a pointer to the last node of the stack
t_stack			*get_last_node(t_stack *stack);
// Adds a new node to the stack
void			append_node(t_stack **a, int nbr);
// Returns a pointer to the node that has the smallest nbr value
t_stack			*find_smallest(t_stack *head);
// Returns a pointer to the node that has the highest nbr value
t_stack			*return_highest_node(t_stack *head);
// Sets the current position of each node in the stack counting from 1
void			set_index(t_stack **stack);

/* Stack Operations */

/* Push functions */
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
/* Swap functions */
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
/* Rotate functions */
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
/* Reverse rotate functions */
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

#endif