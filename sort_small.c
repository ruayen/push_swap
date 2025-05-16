/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:51:58 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-30 10:51:58 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stacks)
{
	int	x;
	int	y;
	int	z;

	x = stacks->a->value;
	y = stacks->a->next->value;
	z = stacks->a->next->next->value;
	if (x < y && y < z)
		return ;
	else if (x > y && x < z)
		sa(stacks);
	else if (x > y && y > z)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (x > y && x > z && y < z)
		ra(stacks);
	else if (x < y && y > z && x < z)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (x < y && y > z && x > z)
		rra(stacks);
}

void	sort_five(t_stack *stacks)
{
	int	pos;
	int	i;
	int	len;

	len = stack_length(stacks->a);
	i = 0;
	if (len == 5)
	{
		while (i < 2)
		{
			pos = find_min_position(stacks->a);
			move_min_to_b(stacks, pos);
			i++;
		}
	}
	else if (len == 4)
	{
		pos = find_min_position(stacks->a);
		move_min_to_b(stacks, pos);
	}
	sort_three(stacks);
	pa(stacks);
	if (len == 5)
		pa(stacks);
}
