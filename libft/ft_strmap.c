/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:50:08 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 23:09:42 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*arr;
	int		i;

	if (!s || !f || !(arr = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
		arr[i++] = (*f)(*s++);
	return (arr);
}
