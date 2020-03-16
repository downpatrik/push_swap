/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:46:01 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 20:08:33 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cmd_instr_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
	}
	return (-1);
}

int	ft_cmd_instr_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_stack_push_front(to, ft_stack_pop_front(from));
		return (1);
	}
	return (-1);
}

int	ft_cmd_instr_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_back(stack, ft_stack_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	ft_cmd_instr_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (-1);
}
