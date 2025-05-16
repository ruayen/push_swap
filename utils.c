/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 09:03:20 by raissaou          #+#    #+#             */
/*   Updated: 2025-04-23 09:03:20 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	return (node);
}

void	push_front(t_node **stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

t_node	*pop_front(t_node **stack)
{
	t_node	*first;

	if (!stack || !*stack)
		return (NULL);
	first = *stack;
	*stack = first -> next;
	first -> next = NULL;
	return (first);
}

void	push_back(t_node **stack, t_node *new_node)
{
	t_node	*current;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
