/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opearation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 10:10:42 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-25 10:10:42 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stacks)
{
	t_node	*node;

	node = pop_front(&stacks->a);
	if (node)
	{
		push_front(&stacks->b, node);
		write(1, "pb\n", 3);
	}
}

void	pa(t_stack *stacks)
{
	t_node	*node;

	node = pop_front(&stacks->b);
	if (node)
	{
		push_front(&stacks->a, node);
		write(1, "pa\n", 3);
	}
}

void	sa(t_stack *stacks)
{
	t_node	*first;
	t_node	*second;

	if (!stacks->a || !stacks->a->next)
		return ;
	first = stacks->a;
	second = stacks->a->next;
	first->next = second->next;
	second->next = first;
	stacks->a = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stacks)
{
	t_node	*first;
	t_node	*second;

	if (!stacks->b || !stacks->b->next)
		return ;
	first = stacks->b;
	second = stacks->b->next;
	first->next = second->next;
	second->next = first;
	stacks->b = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stacks)
{
	t_node	*first;
	t_node	*second;

	if (stacks->a->next)
	{
		first = stacks->a;
		second = stacks->a->next;
		first->next = second->next;
		second->next = first;
		stacks->a = second;
	}
	if (stacks->b->next)
	{
		first = stacks->b;
		second = stacks->b->next;
		first->next = second->next;
		second->next = first;
		stacks->b = second;
	}
	write(1, "ss\n", 3);
}
