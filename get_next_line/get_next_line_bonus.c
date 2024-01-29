/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:09:31 by jeongbel          #+#    #+#             */
/*   Updated: 2024/01/30 07:11:56 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	check_enter(const char *line)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = ft_strlen(line);
	while (i < line_size)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

t_line_lst	*find_lst(t_line_lst **lst, int fd)
{
	t_line_lst	*find_lst;

	if (!(*lst))
	{
		*lst = ft_lstnew(fd);
		return (*lst);
	}
	find_lst = *lst;
	while (1)
	{
		if (find_lst->fd == fd)
			return (find_lst);
		if (!(find_lst->next))
		{
			find_lst->next = ft_lstnew(fd);
			return (find_lst->next);
		}
		find_lst = find_lst->next;
	}
}

void	del_lst(t_line_lst **lst, int fd)
{
	t_line_lst	*now_lst;
	t_line_lst	*next_lst;

	if (!lst || !(*lst))
		return ;
	now_lst = *lst;
	if (now_lst->fd == fd)
	{
		*lst = now_lst->next;
		free(now_lst->line);
		free(now_lst);
		return ;
	}
	while (now_lst)
	{
		next_lst = now_lst->next;
		if (next_lst->fd == fd)
		{
			now_lst->next = next_lst->next;
			free(next_lst->line);
			free(next_lst);
			return ;
		}
		now_lst = next_lst;
	}
}

char	*make_new_line(char *buffer, char **line, size_t read_size)
{
	char	*comb_line;
	char	*new_line;
	size_t	enter;

	comb_line = ft_strjoin(*line, buffer, read_size);
	enter = check_enter(comb_line);
	free(*line);
	*line = 0;
	if (enter < ft_strlen(comb_line) || read_size == 0)
	{
		new_line = ft_substr(comb_line, 0, enter);
		if (new_line)
			*line = ft_substr(comb_line, enter + 1,
					ft_strlen(comb_line) - enter - 1);
		free(comb_line);
		comb_line = 0;
		return (new_line);
	}
	*line = comb_line;
	return (0);
}

char	*get_next_line(int fd)
{
	char					*buffer;
	static t_line_lst		*line_lst;
	t_line_lst				*now_line;
	ssize_t					read_size;
	char					*new_line;

	now_line = find_lst(&line_lst, fd);
	if (!now_line)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		del_lst(&line_lst, fd);
		return (0);
	}
	read_size = 1;
	while (read_size > 0 || now_line->line)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		new_line = make_new_line(buffer, &(now_line->line), read_size);
		if (new_line)
		{
			free(buffer);
			buffer = 0;
			return (new_line);
		}
	}
	free(buffer);
	buffer = 0;
	del_lst(&line_lst, fd);
	return (0);
}
