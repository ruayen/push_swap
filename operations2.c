/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 11:17:53 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-25 11:17:53 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stacks)
{
	t_node	*node;

	if (!stacks->a || !stacks->a->next)
		return ;
	node = pop_front(&stacks->a);
	if (node)
		push_back(&stacks->a, node);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stacks)
{
	t_node	*node;

	if (!stacks->b || !stacks->b->next)
		return ;
	node = pop_front(&stacks->b);
	if (node)
		push_back(&stacks->b, node);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stacks)
{
	t_node	*node;

	if (stacks->a->next)
	{
		node = pop_front(&stacks->a);
		if (node)
			push_back(&stacks->a, node);
	}
	if (stacks->b->next)
	{
		node = pop_front(&stacks->b);
		if (node)
			push_back(&stacks->b, node);
	}
	write(1, "rr\n", 3);
}
