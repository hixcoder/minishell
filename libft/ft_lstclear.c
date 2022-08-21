/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:25:28 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 16:42:44 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_one;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			next_one = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = next_one;
		}
		lst = NULL;
	}
}
