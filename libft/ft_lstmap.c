/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:33:42 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/15 23:15:52 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*now_lst;
	t_list	*temp_lst;

	if (!lst || (*f))
		return (0);
	now_lst = lst;
	new_lst = 0;
	while (now_lst)
	{
		temp_lst = ft_lstnew((*f)(now_lst->content));
		if (!temp_lst)
		{
			if (!now_lst)
				ft_lstclear(&new_lst, (*del));
			return (0);
		}
		now_lst = now_lst->next;
		ft_lstadd_back(&new_lst, temp_lst);
	}
	return (new_lst);
}
