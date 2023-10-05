/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:09:04 by jeongbel          #+#    #+#             */
/*   Updated: 2023/10/05 19:33:56 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	size;

	if (!dst && !src)
		return (0);
	size = 0;
	while (size < n)
	{
		*(unsigned char *)(dst + size) = *(unsigned char *)(src + size);
		size++;
	}
	return (dst);
}
