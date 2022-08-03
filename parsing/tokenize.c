/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:01:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/03 13:28:41 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Type t;
// ARG, // word
// FILE_IN, // '<'
// FILE_OUT, // '>'
// HERE_DOC, // '<<'
// FILE_OUT_APND // '>>'


    
// the ft_tokenize takes the 'word' string and return its type
Type    ft_tokenize(char *word)
{
    if (ft_memcmp(word, "<", ft_strlen(word)) == 0)
        return (FILE_IN);
    else if (ft_memcmp(word, ">", ft_strlen(word)) == 0)
        return (FILE_OUT);
    else if (ft_memcmp(word, "<<", ft_strlen(word)) == 0)
        return (HERE_DOC);
    else if (ft_memcmp(word, ">>", ft_strlen(word)) == 0)
        return (FILE_OUT_APND);
    else
        return (ARG);
}