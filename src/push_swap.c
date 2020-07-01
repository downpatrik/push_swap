/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:34:19 by wvenita           #+#    #+#             */
/*   Updated: 2020/06/19 02:14:00 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_sort_3_element(stacks);
	else if (stacks->count_a <= 5)
		ft_sort_5_element(stacks);
	else
		ft_global_sort(stacks);
}

int				main(int ac, char **av)
{
	t_data		*new;
	t_stacks	*stacks;

	if (ac < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	ft_null(stacks, new);
	if (ft_validation(ac, av))
	{
		ft_array_separation(ac, av, new);
		ft_duplicate_check(new, stacks);
		if (ft_is_sorted(new))
		{
			ft_init_stack(new, stacks);
			ft_sort(stacks);
			ft_free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
