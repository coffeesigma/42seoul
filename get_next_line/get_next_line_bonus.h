/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:10:50 by jeongbel          #+#    #+#             */
/*   Updated: 2024/01/30 06:12:54 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line_lst
{
	char				*line;
	int					fd;
	struct s_line_lst	*next;
}	t_line_lst;

size_t		ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2, const size_t read_size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
t_line_lst	*ft_lstnew(int fd);
size_t		check_enter(const char *line);
t_line_lst	*find_lst(t_line_lst **lst, int fd);
void		del_lst(t_line_lst **lst, int fd);
char		*make_new_line(char *buffer, char **line, size_t read_size);
char		*get_next_line(int fd);

#endif
