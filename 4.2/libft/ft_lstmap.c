/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:55:08 by mde-laga          #+#    #+#             */
/*   Updated: 2018/11/20 11:07:13 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = f(lst);
	if (lst->next)
		new_lst->next = ft_lstmap(lst->next, f);
	else
		new_lst->next = NULL;
	return (new_lst);
}
