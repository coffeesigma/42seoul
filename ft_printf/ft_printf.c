/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbel <jeongbel@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:19:50 by jeongbel          #+#    #+#             */
/*   Updated: 2024/02/03 19:40:05 by jeongbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list con_list;
	size_t i;
	
	//printf("start printf\n");
	va_start(con_list, format);
	i = 0;
	int ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret++;
			if (format[i + 1] == 'c')
			{
				char c = (char)va_arg(con_list, int);
				write(1, &c, 1);
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(con_list, char *);
				write(1, s, ft_strlen(s));
			}
			else if (format[i + 1] == 'p')
			{

			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				char *out = ft_itoa(va_arg(con_list, int));
				write(1, out, ft_strlen(out));
			}
			// else if (format[i + 1] == 'u')
			// else if (format[i + 1] == 'x')
			// else if (format[i + 1] == 'X')
			// else if (format[i + 1] == '%')
			i += 2;
			continue ;
		}
		write(1, &format[i], 1);
		i++;
	}

	return (ret);
}
