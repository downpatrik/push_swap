/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:12:05 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/15 23:44:03 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tf, size_t nb)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (tf[0] == '\0')
		return ((char*)str);
	while (str[i] && i < nb)
	{
		if (str[i] == tf[0])
		{
			n = 1;
			while (str[i + n] == tf[n] && tf[n] != '\0' && (i + n) < nb)
				n++;
			if (tf[n] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
