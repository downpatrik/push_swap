/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:05:15 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/15 22:51:23 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_is_dupl(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void ft_print_stack(t_stacks *stacks)
{
	t_stack *a;
	t_stack *b;

	a = stacks->a;
	b = stacks->b;
	while (a || b)
	{
		if (a)
			ft_putnbr(a->val);
		else
			ft_putchar('-');
		ft_putstr(" | ");
		if (b)
			ft_putnbr(b->val);
		else
			ft_putchar('-');
		ft_putchar('\n');
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}
	ft_putchar('\n');
}

int ft_get_count_list(t_stack *stack)
{
	int count;

	count = 0;
	while (stack && ++count)
		stack = stack->next;
	return (count);
}

static int ft_cmd_instr(char *instr, t_stacks *stacks)
{
	int len;
	int res;

	len = ft_strlen(instr);
	res = 0;
	if (len == 2 && (!ft_strcmp(instr, "ss") || !ft_strcmp(instr, "sa")))
		res = ft_cmd_instr_s(&stacks->a);
	if (len == 2 && (!ft_strcmp(instr, "ss") || !ft_strcmp(instr, "sb")))
		res = ft_cmd_instr_s(&stacks->b);
	if (len == 2 && !ft_strcmp(instr, "pa"))
		res = ft_cmd_instr_p(&stacks->b, &stacks->a);
	if (len == 2 && !ft_strcmp(instr, "pb"))
		res = ft_cmd_instr_p(&stacks->a, &stacks->b);
	if (len == 2 && (!ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rr")))
		res = ft_cmd_instr_r(&stacks->a);
	if (len == 2 && (!ft_strcmp(instr, "rb") || !ft_strcmp(instr, "rr")))
		res = ft_cmd_instr_r(&stacks->b);
	if (len == 3 && (!ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrr")))
		res = ft_cmd_instr_rr(&stacks->a);
	if (len == 3 && (!ft_strcmp(instr, "rrb") || !ft_strcmp(instr, "rrr")))
		res = ft_cmd_instr_rr(&stacks->b);
	return (res == 0 ? 0 : 1);
}

void ft_cmd_instr_cnt(char *instr, int count, t_stacks *stacks)
{
	int i;

	i = ft_abs(count);
	while (i--)
	{
		if (ft_cmd_instr(instr, stacks))
		{
			if (stacks->cmd_print == 1)
				ft_putendl(instr);
			if (stacks->cmd_print == 0 && stacks->flag_v == 1)
				ft_print_stack(stacks);
			stacks->cmds_cnt++;
		}
		else
			ft_put_error(&stacks, 0);
	}
}