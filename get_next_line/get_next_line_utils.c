/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:50:07 by jeongbel          #+#    #+#             */
/*   Updated: 2024/01/30 00:13:54 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(const char *s1, const char *s2, const size_t read_size)
{
	char	*join;
	size_t	i;
	size_t	s1_size;

	s1_size = ft_strlen(s1);
	if (s1_size + read_size <= 0)
		return (0);
	join = (char *)malloc(sizeof(char) * (s1_size + read_size + 1));
	if (!join)
		return (0);
	i = 0;
	while (i < s1_size)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < s1_size + read_size)
	{
		join[i] = s2[i - s1_size];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	s_size;

	s_size = ft_strlen(s);
	if (!s)
		return (0);
	if (s[len + start] == '\n')
		len++;
	if (!len)
		return (0);
	if (s_size > len + start)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else if (s_size > start)
		sub = (char *)malloc(sizeof(char) * (s_size - start + 1));
	else
		sub = (char *)malloc(sizeof(char));
	if (!sub)
		return (0);
	i = -1;
	while (++i < len && i + start < s_size)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
