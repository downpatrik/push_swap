/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:54:28 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/15 23:38:50 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		i;
	size_t	n;

	i = -1;
	n = ft_strlen(dest);
	while (src[++i] && nb--)
		dest[n + i] = src[i];
	dest[n + i] = '\0';
	return (dest);
}
