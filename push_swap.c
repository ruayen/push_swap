/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 08:33:39 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-23 08:33:39 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *stacks, int argc, char **argv)
{
	t_node	*node;
	int		i;
	int		val;

	stacks->a = NULL;
	stacks->b = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		node = create_node(val);
		if (!node)
		{
			free_stack(stacks);
			return (0);
		}
		push_back(&stacks->a, node);
		i++;
	}
	return (1);
}

int	stack_length(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sort_stack(t_stack *stacks)
{
	int	len;

	if (is_sorted(stacks->a))
		return ;
	len = stack_length(stacks->a);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(stacks);
	}
	else if (len == 3)
		sort_three(stacks);
	else if (len <= 5)
		sort_five(stacks);
	else if (len <= 100)
		chunk_sort(stacks);
	else
		chunk_sort(stacks);
}

void	free_stack(t_stack *stacks)
{
	t_node	*tmp;

	while (stacks->a)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free(tmp);
	}
	while (stacks->b)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!init_stack(&stacks, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	sort_stack(&stacks);
	free_stack(&stacks);
	return (0);
}
