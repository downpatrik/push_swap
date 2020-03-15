/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:38:57 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/14 23:39:14 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	t_i64	res;
	int		minus;

	res = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		minus = 45 % *str++ - 1;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (t_i32)(minus * res);
}
