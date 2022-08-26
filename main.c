/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/25 16:48:26 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_get_value(t_data *data, char *key)
{
   t_list *tmp;

   tmp = data->env_2;
   while (tmp)
   {
      if (ft_strncmp(key, tmp->content, ft_strlen(key)) == 0)
         return (ft_strchr(tmp->content, '=') + 1);
      tmp = tmp->next;
   }
   return (NULL);
}

int init_env(t_data *data)
{
   int i;
   t_list *head;
   t_list *new;
   char *content;

   i = 1;
   if ((content = ft_strdup(data->env[0])) == NULL)
      return (minishell_perror(MEM), 0);
   if ((head = ft_lstnew(content)) == NULL)
      return (minishell_perror(MEM), 0);
   while (data->env[i])
   {
      if ((content = ft_strdup(data->env[i])) == NULL)
         return (minishell_perror(MEM), 0);
      if ((new = ft_lstnew(content)) == NULL)
         return (minishell_perror(MEM), 0);
      ft_lstadd_back(&head, new);
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
   data.exit_status = 0;
   ft_readline(&data);
   return (0);
}