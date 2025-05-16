/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 09:20:09 by raissaou          #+#    #+#             */
/*   Updated: 2025-05-12 09:20:09 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(int argc, char **argv, int current)
{
	int	i;

	(void)argc;
	i = 1;
	while (i < current)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[current]))
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	validate_args(int argc, char **argv)
{
	int		i;
	long	val;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		val = ft_atol(argv[i]);
		if (val < -2147483648 || val > 2147483647)
			return (0);
		if (has_duplicate(argc, argv, i))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
