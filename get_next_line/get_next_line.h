/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:16:51 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:10 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);
size_t	ft_strlen2(const char *str);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strdup2(const char *s1);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
#endif
