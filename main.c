/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/23 10:02:48 by hboumahd         ###   ########.fr       */
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
   ft_readline(&data);
   return (0);
}