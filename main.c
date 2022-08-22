/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/21 19:13:16 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int init_env(t_data *data)
{
   int i;
   t_list *head;
   char *content;

   i = 1;
   if ((content = ft_strdup(data->env[0])) == NULL)
      return (0);
   head = ft_lstnew(content);
   while (data->env[i])
   {
      if ((content = ft_strdup(data->env[i])) == NULL)
         return 0;
      ft_lstadd_back(&head, ft_lstnew(content));
      i++;
   }
   data->env_2 = head;
   return 1;
}

int main(int ac, char **av, char **env)
{
   t_data data;
   (void)av;
   (void)ac;
   data.env = env;
   init_env(&data);
   ft_readline(&data);
   return (0);
}