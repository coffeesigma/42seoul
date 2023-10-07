/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:37:15 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/07 21:14:10 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	point;

	point = ft_strlen(s);
	while (point > 0)
	{
		if ((char)c == *(s + point))
			return ((char *)s + point);
		point--;
	}
	if ((unsigned char)c == *(s + point))
		return ((char *)s);
	return (0);
}
