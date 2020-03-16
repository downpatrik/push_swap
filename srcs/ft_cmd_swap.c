/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:55:50 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 20:11:49 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*ft_get_last_list(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void			ft_stack_push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack			*ft_stack_pop_front(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void			ft_stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_get_last_list(*stack);
	last->next = new;
}

t_stack			*ft_stack_pop_back(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (last->next && last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
	}
	return (tmp);
}
