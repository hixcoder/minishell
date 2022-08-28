/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/28 17:20:14 by ahammam          ###   ########.fr       */
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

int ft_env_is_empty(t_data *data)
{

   t_list *head;
   t_list *next1;
   t_list *next2;

   head = ft_lstnew(ft_strdup("SHLVL=1"));
   next1 = ft_lstnew(ft_pwd2("PWD="));
   next2 = ft_lstnew(ft_pwd2("OLDPWD="));
   ft_lstadd_back(&head, next1);
   ft_lstadd_back(&head, next2);
   data->env_2 = head;
   return (0);
}

int init_env(t_data *data, char **env)
{
   int i;
   t_list *head;
   t_list *new;
   char *content;
   int lvl;

   i = 1;
   lvl = -2;
   if (env[0] == NULL)
      return (ft_env_is_empty(data));
   content = ft_strdup(env[0]);
   head = ft_lstnew(content);
   while (env[i])
   {
      if (!ft_strncmp(env[i], "SHLVL", 5) && ((env[i])[5] == '='))
      {
         lvl = ft_atoi(env[i] + 6);
         if (lvl < 0)
            lvl = -1;
         content = ft_strjoin("SHLVL=",
                              ft_itoa(lvl + 1));
      }
      else
         content = ft_strdup(env[i]);
      new = ft_lstnew(content);
      ft_lstadd_back(&head, new);
      i++;
   }
   if (lvl == -2)
   {
      content = ft_strdup("SHLVL=1");
      new = ft_lstnew(content);
      ft_lstadd_back(&head, new);
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
   init_env(&data, env);
   g_var.exit_status = 0;
   ft_readline(&data);
   return (0);
}