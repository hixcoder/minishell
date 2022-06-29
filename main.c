/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:11:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/06/29 13:52:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_readline(t_data *data)
{
    while (1)
    {
        data->args = readline("Minishell => ");
        if (ft_strlen(data->args) > 0)
            add_history(data->args);
        else if (!ft_strncmp(data->args, "hello", 5))
            system("ls");
    }
}

int main()
{
   t_data data;

   ft_readline(&data);
   return (0);
}