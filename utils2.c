/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 08:07:34 by raissaou          #+#    #+#             */
/*   Updated: 2025-05-05 08:07:34 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_node *stack)
{
	int		min;
	int		pos;
	int		i;
	t_node	*current;

	if (!stack)
		return (-1);
	min = stack->value;
	pos = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	move_min_to_b(t_stack *stacks, int pos)
{
	int	len;

	len = stack_length(stacks->a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(stacks);
	}
	else
	{
		pos = len - pos;
		while (pos-- > 0)
			rra(stacks);
	}
	pb(stacks);
}

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
