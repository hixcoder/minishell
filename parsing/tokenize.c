/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/07 21:44:34 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

  
// the ft_tokenize takes the 'word' string and return its type
Type    ft_tokenize(char *word)
{
    if (ft_memcmp(word, "<", ft_strlen(word)) == 0)
        return (REDIRECT_IN);
    else if (ft_memcmp(word, ">", ft_strlen(word)) == 0)
        return (REDIRECT_OUT);
    else if (ft_memcmp(word, "<<", ft_strlen(word)) == 0)
        return (HERE_DOC);
    else if (ft_memcmp(word, ">>", ft_strlen(word)) == 0)
        return (REDIRECT_OUT_APND);
    else
        return (ARG);
}