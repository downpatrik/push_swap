/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:38:57 by wvenita           #+#    #+#             */
/*   Updated: 2020/06/19 02:10:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	t_i64	res;
	int		minus;
	int		dig;

	res = 0;
	minus = 1;
	dig = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		minus = 45 % *str++ - 1;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str++ - '0';
		dig++;
		if (dig > 10 || minus * res > 2147483647
			|| minus * res < (-2147483648))
			ft_error();
	}
	return (t_i32)(minus * res);
}
