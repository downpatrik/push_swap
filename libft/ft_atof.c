/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:18:15 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/18 00:13:52 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	res;
	int		minus;
	int		exp;

	res = 0.0;
	minus = 1;
	exp = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		minus = 45 % *str++ - 1;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	if (*str++ == '.')
		while (ft_isdigit(*str))
			res = res + (*str++ - '0') / ft_pow(10, exp++);
	if ((*str == 'e' || *str == 'E') && str++)
	{
		exp = ft_atoi(str);
		exp = (exp > 0) ? ft_pow(10, exp) : (1 / ft_pow(10, exp));
		res *= exp;
	}
	return (minus * res);
}
