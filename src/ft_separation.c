/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:18:13 by wvenita           #+#    #+#             */
/*   Updated: 2020/06/19 02:14:27 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_array_separation(int ac, char **av, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	char	**mass;
	int		count_element;

	i = 1;
	while (i < ac)
	{
		p = -1;
		count_element = ft_wordcount(av[i], ' ');
		mass = ft_strsplit(av[i], ' ');
		if (!(buff = (int *)malloc(sizeof(int) * (count_element))))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new, buff, count_element);
		i++;
	}
}

void		ft_stacking(t_data *new, int *buff, int count)
{
	int		i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}

int			*ft_intarrcpy(int *dst, const int *src, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
