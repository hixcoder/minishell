/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubunto <ubunto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:37:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/08/28 23:44:57 by ubunto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// this one check if the suggested file name is already exist in the "/tmp" path
static int	check_file_name(char *file)
{
	DIR				*folder;
	struct dirent	*item;

	folder = opendir("/tmp");
	if (!folder)
		return (0);
	item = readdir(folder);
	while (item)
	{
		if (ft_strcmp(item->d_name, file) == 0)
		{
			closedir(folder);
			return (1); 
		}
		item = readdir(folder);
	}
	closedir(folder);
	return (0);
}

// this one generate the herdoc file name ,
// it should not be exist in the "/tmp" path
char	*ft_get_file_name(void)
{
	int		i;
	char	*name;
	char	*file_name;

	i = 0;
	name = ft_itoa(i);
	while (check_file_name(name))
	{
		free(name);
		i++;
		name = ft_itoa(i);
	}
	file_name = ft_strjoin("/tmp/", name);
	free(name);
	return (file_name);
}

// this function creates the herdoc file
// chmod numbers: 4(r) + 2(w) + 1(x)
void	ft_create_herdoc_file(t_data *data, int i, int j, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0600);
	if (fd == -1)
		return ;
	write(1, "Heredoc> ", 9);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "\n") == 0)
		{
			write(1, "Heredoc> ", 9);
			write(fd, line, ft_strlen(line));
			continue ;
		}
		line[ft_strlen(line) - 1] = '\0';
		if (strcmp(line, data->cmds[i].words[j + 1]->w) != 0)
		{
			write(1, "Heredoc> ", 9);
			write(fd, line, ft_strlen(line));
		}
		else
			break ;
		line = get_next_line(0);
	}
	close(fd);
}

// this function updates the herdoc infos(type, file)
void	ft_update_herdoc_info(t_data *data, int i, char *file_name)
{
	int	j;

	j = -1;
	while (data->cmds[i].words[++j])
	{
		if (data->cmds[i].words[j]->t == HERE_DOC)
		{
			data->cmds[i].words[j]->t = REDIRECT_IN;
			free(data->cmds[i].words[j + 1]->w);
			data->cmds[i].words[j + 1]->w = ft_strdup(file_name);
		}
	}
	free(file_name);
}
