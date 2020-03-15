/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:13:01 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/16 23:25:38 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*new_str;
	char	*tmp;
	size_t	size;

	size = ft_strlen(str);
	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_str[size] = '\0';
	tmp = new_str;
	while (size--)
		*tmp++ = *(str + size);
	return (new_str);
}
