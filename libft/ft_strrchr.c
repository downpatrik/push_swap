/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:25:17 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 22:01:18 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*s)
		s++;
	if (c == '\0')
		return ((char*)s);
	while (str <= s)
		if (*s-- == c)
			return ((char*)++s);
	return (NULL);
}
