/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 09:06:57 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-30 09:06:57 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_back(t_node **stack)
{
	t_node	*current;
	t_node	*prev;

	if (!stack || !*stack)
		return (NULL);
	current = *stack;
	if (!current -> next)
	{
		*stack = NULL;
		return (current);
	}
	while (current->next)
	{
		prev = current;
		current = current -> next;
	}
	prev->next = NULL;
	return (current);
}

void	rra(t_stack *stacks)
{
	t_node	*node;

	if (!stacks->a || !stacks->a->next)
		return ;
	node = pop_back(&stacks->a);
	if (node)
		push_front(&stacks->a, node);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stacks)
{
	t_node	*node;

	if (!stacks->b || !stacks->b->next)
		return ;
	node = pop_back(&stacks->b);
	if (node)
		push_front(&stacks->b, node);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stacks)
{
	t_node	*node;

	if (stacks->a->next)
	{
		node = pop_back(&stacks->a);
		if (node)
			push_front(&stacks->a, node);
	}
	if (stacks->b->next)
	{
		node = pop_back(&stacks->b);
		if (node)
			push_front(&stacks->b, node);
	}
	write(1, "rrr\n", 4);
}
