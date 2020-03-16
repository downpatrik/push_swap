/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:21:44 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 21:14:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->i = i;
		i++;
		stack = stack->next;
	}
}

t_stack	*ft_get_max_sort(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*max;
	int		count;
	int		i;

	first = stack;
	max = stack;
	count = ft_get_count_list(stack);
	while (stack)
	{
		tmp = stack;
		i = 0;
		while (i < count)
		{
			if ((tmp->next == NULL ? first : tmp->next)->val < tmp->val)
				break ;
			stack->sort++;
			i++;
			tmp = tmp->next == NULL ? first : tmp->next;
		}
		max = stack->sort >= max->sort ? stack : max;
		stack = stack->next;
	}
	return (max);
}

int		ft_list_iter_to_up(int stack_len, int list_i)
{
	return (stack_len / 2 >= list_i ? list_i : (stack_len - list_i) * -1);
}

int		ft_get_list_place_i(t_stack *stack, int list_val)
{
	t_stack	*optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (stack)
	{
		if ((last_min == 0) ||
			(last_min < 0 && stack->val - list_val < 0 &&
			stack->val - list_val > last_min) ||
			(last_min > 0 && stack->val - list_val < last_min))
		{
			last_min = stack->val - list_val;
			optim = stack;
		}
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	if (optim == stack && last_min < 0)
		return (-1);
	return (last_min < 0 ? optim->i + 1 : optim->i);
}

int		ft_list_b_to_a_count(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && place_b != -1)
		return (ft_abs(a) > ft_abs(b) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
}
