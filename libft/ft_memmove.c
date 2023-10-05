/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:48:42 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/05 20:53:34 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
	size_t			size;
	unsigned char	src_str;

	if (!dst && !src)
		return (0);
	
	size = 0;
	while (size < len)
	{
		*(unsigned char *)(dst + size) = *(unsigned char *)(src + size);
		size++;
	}
	return (dst);
}