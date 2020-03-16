/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:59:33 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 22:01:57 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_st_a_norm(t_stacks *stacks)
{
	int	instr;

	ft_set_index(stacks->a);
	stacks->max_sort = ft_get_max_sort(stacks->a);
	stacks->len_a = ft_get_count_list(stacks->a);
	instr = stacks->len_a - stacks->max_sort->i - stacks->max_sort->sort;
	instr = instr > 0 ? stacks->len_a - (instr) : ft_abs(instr);
	instr = ft_list_iter_to_up(stacks->len_a, instr);
	ft_cmd_instr_cnt(instr > 0 ? "ra" : "rra", instr, stacks);
}

void	ft_st_a_to_b(t_stacks *stacks)
{
	t_stack	*a;

	a = stacks->a;
	while (a && a->i != stacks->max_sort->i)
	{
		a = a->next;
		ft_cmd_instr_cnt("pb", 1, stacks);
	}
}

void	ft_st_b_to_a(t_stacks *stacks)
{
	t_stack	*b;
	int		min_instr;
	int		instr;

	while (stacks->b)
	{
		b = stacks->b;
		ft_set_index(stacks->a);
		ft_set_index(stacks->b);
		stacks->len_a = ft_get_count_list(stacks->a);
		stacks->len_b = ft_get_count_list(stacks->b);
		min_instr = ft_st_set_tmp_cmds(stacks, b);
		ft_st_copy_tmp_to_opt_cmds(stacks);
		while (b)
		{
			instr = ft_st_set_tmp_cmds(stacks, b);
			if (min_instr > instr)
			{
				min_instr = instr;
				ft_st_copy_tmp_to_opt_cmds(stacks);
			}
			b = b->next;
		}
		ft_list_b_to_a(stacks);
	}
}

void	ft_list_b_to_a(t_stacks *stcks)
{
	stcks->tmp_a = ft_abs(stcks->opt_a);
	stcks->tmp_b = ft_abs(stcks->opt_b);
	while (((stcks->opt_a > 0 && stcks->opt_b > 0) ||
			(stcks->opt_a < 0 && stcks->opt_b < 0)) &&
			stcks->tmp_a && stcks->tmp_b && stcks->opt_pl != 1)
	{
		ft_cmd_instr_cnt(stcks->opt_b > 0 ? "rr" : "rrr", 1, stcks);
		stcks->tmp_a--;
		stcks->tmp_b--;
	}
	ft_cmd_instr_cnt(stcks->opt_b > 0 ? "rb" : "rrb", stcks->tmp_b, stcks);
	if (stcks->opt_pl != -1)
		ft_cmd_instr_cnt(stcks->opt_a > 0 ? "ra" : "rra", stcks->tmp_a, stcks);
	ft_cmd_instr_cnt("pa", 1, stcks);
	if (stcks->opt_pl == -1)
		ft_cmd_instr_cnt("ra", 1, stcks);
}

void	ft_st_a_min_to_top(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*min_list;
	int		iter_to_up;

	a = stacks->a;
	min_list = a;
	while (a)
	{
		min_list = a->val < min_list->val ? a : min_list;
		a = a->next;
	}
	stacks->len_a = ft_get_count_list(stacks->a);
	ft_set_index(stacks->a);
	iter_to_up = ft_list_iter_to_up(stacks->len_a, min_list->i);
	ft_cmd_instr_cnt(iter_to_up > 0 ? "ra" : "rra", iter_to_up, stacks);
}
