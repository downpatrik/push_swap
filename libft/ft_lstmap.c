/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:08:14 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/17 23:58:44 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *elem, size_t size)
{
	free(elem);
	(void)size;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = ft_lstnew(lst->content, lst->content_size);
	list = f(temp);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		temp = ft_lstnew(lst->content, lst->content_size);
		if (!(list->next = f(temp)))
		{
			ft_lstdel(&new, &ft_del);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
