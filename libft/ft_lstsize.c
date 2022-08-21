/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:38:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/19 17:42:01 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void ft_lstprint(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
		i++;
	}
}
