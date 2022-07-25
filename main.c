/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/25 11:04:15 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int main(int ac, char **av, char **env)
{
   t_data data;
   (void) av;
   (void) ac;
   (void) env;
   // for(int i = 0; env[i]; i++)
   //    printf("%s\n", env[i]);
   printf("Main program started\n");
  char* argv[] = {"ls", NULL };
  char* envp[] = { "some", "environment", NULL };
  if (execve("/bin/ls", argv, envp) == -1)
    perror("Could not execve");
   ft_readline(&data);
   return (0);
}