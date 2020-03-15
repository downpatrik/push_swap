/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:37:59 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/15 21:25:52 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void ft_stack_free(t_stack **stack)
{
	t_stack *next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int ft_stacks_free(t_stacks **stacks, int return_val)
{
	if (*stacks && (*stacks)->a)
		ft_stack_free(&(*stacks)->a);
	if (*stacks && (*stacks)->b)
		ft_stack_free(&(*stacks)->b);
	if (*stacks)
		free(*stacks);
	return (return_val);
}

void ft_put_error(t_stacks **stacks, int return_value)
{
	ft_putendl("Error");
	ft_stacks_free(stacks, return_value);
	exit(return_value);
}

void ft_st_copy_tmp_to_opt_cmds(t_stacks *stacks)
{
	stacks->opt_pl = stacks->tmp_pl;
	stacks->opt_a = stacks->tmp_a;
	stacks->opt_b = stacks->tmp_b;
}

int ft_st_set_tmp_cmds(t_stacks *stacks, t_stack *stack_b)
{
	stacks->tmp_pl = ft_get_list_place_i(stacks->a, stack_b->val);
	stacks->tmp_b = ft_list_iter_to_up(stacks->len_b, stack_b->i);
	stacks->tmp_a = ft_list_iter_to_up(stacks->len_a, stacks->tmp_pl);
	return (ft_list_b_to_a_count(stacks->tmp_a, stacks->tmp_b, stacks->tmp_pl));
}