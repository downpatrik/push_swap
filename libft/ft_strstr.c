/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:46:06 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/15 23:43:58 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		n;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			n = 1;
			while (str[i + n] == to_find[n] && to_find[n] != '\0')
				n++;
			if (to_find[n] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
