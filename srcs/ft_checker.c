/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:15:14 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/15 21:25:15 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int ft_is_sort_stacks(t_stacks *stacks)
{
	t_stack *a;
	int tmp;

	if (stacks->b != NULL)
		return (0);
	a = stacks->a;
	tmp = a->val;
	while (a)
	{
		if (tmp > a->val)
			return (0);
		tmp = a->val;
		a = a->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stacks *stacks;
	char *instr;

	stacks = ft_create_stacks(ac, av);
	stacks->cmd_print = 0;
	if (stacks->a == NULL)
		exit(ft_stacks_free(&stacks, 0));
	while (get_next_line(0, &instr))
	{
		ft_cmd_instr_cnt(instr, 1, stacks);
		if (instr)
			free(instr);
	}
	ft_is_sort_stacks(stacks) ? ft_putendl("OK") : ft_putendl("KO");
	return (ft_stacks_free(&stacks, 0));
}