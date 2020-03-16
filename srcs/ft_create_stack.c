/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:44:33 by wvenita           #+#    #+#             */
/*   Updated: 2020/03/16 20:10:53 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*ft_create_new_list(int val)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

static t_stack	*ft_stack_push_back_int(t_stack **stack, int val)
{
	t_stack	*new;

	if ((new = ft_create_new_list(val)) == NULL)
		return (NULL);
	ft_stack_push_back(stack, new);
	return (*stack);
}

static int		ft_is_valid_int(int val, char *av)
{
	char	*cur;
	int		res;

	res = 0;
	cur = ft_itoa(val);
	if (ft_strcmp(cur, av) == 0)
		res = 1;
	if (cur)
		free(cur);
	return (res);
}

static void		ft_create_stack_a(int ac, char **av, t_stacks *stacks)
{
	int	i;
	int	val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			stacks->flag_v = 1;
		else if (ft_strcmp(av[i], "-c") == 0)
			stacks->flag_c = 1;
		else
		{
			val = ft_atoi(av[i]);
			if (ft_is_valid_int(val, av[i]) == 0 ||
				ft_is_dupl(stacks->a, val) == 0 ||
				ft_stack_push_back_int(&stacks->a, val) == NULL)
				ft_put_error(&stacks, ft_free_array(ac == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL, 1);
}

t_stacks		*ft_create_stacks(int ac, char **av)
{
	t_stacks	*stacks;

	if ((stacks = (t_stacks *)malloc(sizeof(t_stacks))) == NULL)
		ft_put_error(&stacks, 1);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->flag_v = 0;
	stacks->cmds_cnt = 0;
	stacks->cmd_print = 0;
	ft_create_stack_a(ac, av, stacks);
	return (stacks);
}
