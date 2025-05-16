/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 08:34:33 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-23 08:34:33 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h> 

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

t_node	*create_node(int value);
void	push_front(t_node **stack, t_node *new_node);
t_node	*pop_front(t_node **stack);
int		ft_atoi(char *nptr);
long	ft_atol(const char *str);
void	push_back(t_node **stack, t_node *new_node);
t_node	*pop_back(t_node **stack);
int		find_min_position(t_node *stack);
void	move_min_to_b(t_stack *stacks, int pos);
void	pb(t_stack *stacks);
void	pa(t_stack *stacks);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	sort_three(t_stack *stacks);
void	sort_five(t_stack *stacks);
void	assign_indexes(t_node *stack);
int		init_stack(t_stack *stacks, int argc, char **argv);
int		stack_length(t_node *stack);
void	sort_stack(t_stack *stacks);
void	free_stack(t_stack *stacks);
int		is_number(const char *str);
int		has_duplicate(int argc, char **argv, int current);
int		validate_args(int argc, char **argv);
void	chunk_sort(t_stack *stacks);
int		is_sorted(t_node *stack);

#endif