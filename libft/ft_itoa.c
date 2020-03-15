/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:45:04 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/09 21:33:05 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;
	t_i64	temp;
	int		i;

	temp = n;
	size = 1;
	while (temp /= 10)
		size++;
	if (n < 0)
		size++;
	if (!(arr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
		arr[i++] = size-- ? '-' : '-';
	temp = (n < 0) ? -1 * (t_i64)n : n;
	while (size--)
	{
		arr[i++] = temp / ft_pow(10, size) + 48;
		temp %= ft_pow(10, size);
	}
	arr[i] = '\0';
	return (arr);
}
