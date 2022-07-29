/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/07/29 16:29:01 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int main(int ac, char **av, char **env)
{
   t_data data;
   (void) av;
   (void) ac;
   data.env = env;
   char *s = "hello '$xx'$sdfds $xx$xx $gg";
	char *w1 = "xx";
	char *w2 = NULL;
   printf("s: %s\nold_w: %s\nnew_w: %s\n---------\n", s, w1, w2);
	printf("===> %s\n", ft_strreplace(s, w1, w2));
   // ft_readline(&data);
   return (0);
}