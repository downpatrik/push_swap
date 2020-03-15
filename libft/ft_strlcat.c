/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:01:56 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 23:09:29 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ssize;
	size_t	dsize;
	size_t	k;

	ssize = ft_strlen(src);
	dsize = ft_strnlen(dest, size);
	if (dsize == size)
		return (dsize + ssize);
	k = 0;
	while (src[k] && (dsize + k + 1) < size)
	{
		dest[dsize + k] = src[k];
		k++;
	}
	if ((dsize + k) < size)
		dest[dsize + k] = '\0';
	return (dsize + ssize);
}
