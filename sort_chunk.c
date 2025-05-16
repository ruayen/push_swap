/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 09:20:28 by raissaou          #+#    #+#             */
/*   Updated: 2025-05-12 09:20:28 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_position(t_node *stack)
{
	int		max_index;
	int		pos;
	int		i;
	t_node	*tmp;

	max_index = -1;
	i = 0;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	push_back_to_a(t_stack *stacks)
{
	int	pos;
	int	len;

	while (stack_length(stacks->b) > 0)
	{
		pos = find_max_index_position(stacks->b);
		len = stack_length(stacks->b);
		if (pos <= len / 2)
		{
			while (pos-- > 0)
				rb(stacks);
		}
		else
		{
			while (pos++ < len)
				rrb(stacks);
		}
		pa(stacks);
	}
}

void	push_chunks_to_b(t_stack *stacks, int total_size, int chunk_count)
{
	int	chunk_size;
	int	current_index;

	chunk_size = total_size / chunk_count;
	current_index = 0;
	while (stack_length(stacks->a) > 0)
	{
		if (stacks->a->index <= current_index)
		{
			pb(stacks);
			rb(stacks);
			current_index++;
		}
		else if (stacks->a->index <= current_index + chunk_size)
		{
			pb(stacks);
			current_index++;
		}
		else
			ra(stacks);
	}
}

int	num_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (13);
	return (20);
}

void	chunk_sort(t_stack *stacks)
{
	int	size;
	int	num;

	size = stack_length(stacks->a);
	num = num_chunks(size);
	assign_indexes(stacks->a);
	push_chunks_to_b(stacks, size, num);
	push_back_to_a(stacks);
}
