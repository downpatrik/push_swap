/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:59:50 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/15 22:51:13 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void ft_sort_three(t_stacks *stacks)
{
	if (stacks->a->val > stacks->a->next->val &&
		stacks->a->val < stacks->a->next->next->val)
		ft_cmd_instr_cnt("sa", 1, stacks);
	else if (stacks->a->val > stacks->a->next->next->val)
		ft_cmd_instr_cnt("ra", 1, stacks);
}

static void ft_sort_five(t_stacks *stacks)
{
	if (stacks->max_sort->sort < 3)
	{
		ft_cmd_instr_cnt("pb", 2, stacks);
		ft_sort_three(stacks);
	}
	else
		ft_st_a_to_b(stacks);
	ft_st_b_to_a(stacks);
	ft_st_a_min_to_top(stacks);
}

static void ft_sort_other(t_stacks *stacks)
{
	ft_st_a_to_b(stacks);
	ft_st_b_to_a(stacks);
	ft_st_a_min_to_top(stacks);
}

int main(int ac, char **av)
{
	t_stacks *stacks;

	stacks = ft_create_stacks(ac, av);
	if (stacks->a == NULL)
		exit(ft_stacks_free(&stacks, 0));
	stacks->cmd_print = 1;
	stacks->len_a = ft_get_count_list(stacks->a);
	ft_st_a_norm(stacks);
	if (stacks->len_a == 3)
		ft_sort_three(stacks);
	else if (stacks->len_a == 5)
		ft_sort_five(stacks);
	else
		ft_sort_other(stacks);
	return (ft_stacks_free(&stacks, 0));
}