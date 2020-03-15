/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:10:02 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 23:12:24 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*arr;
	int		size;

	size = 0;
	if (!s)
		return (NULL);
	while (ft_isspace((char)*s))
		s++;
	if (!(size = ft_strlen(s)))
		return (ft_strnew(0));
	while (ft_isspace(*(s + size - 1)))
		size--;
	if (!(arr = ft_strnew(size)))
		return (NULL);
	ft_strncpy(arr, s, size);
	arr[size] = '\0';
	return (arr);
}
