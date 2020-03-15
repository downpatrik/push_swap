/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:00:41 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 23:09:17 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		i;
	size_t		j;
	size_t		size;

	i = s1 ? ft_strlen(s1) : 0;
	j = s2 ? ft_strlen(s2) : 0;
	size = i + j;
	if (!(arr = ft_strnew(size)))
		return (NULL);
	if (i)
		ft_strcpy(arr, s1);
	if (j)
		ft_strcat(arr, s2);
	arr[size] = '\0';
	return (arr);
}
