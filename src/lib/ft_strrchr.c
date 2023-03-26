/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:34:24 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 16:39:20 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*conv_str;
	int		i;
	int		len;

	i = 0;
	conv_str = (char *)str;
	len = ft_strlen(conv_str);
	while (i <= len)
	{
		if (conv_str[len - i] == (char)c)
		{
			return (&conv_str[len - i]);
		}
		i++;
	}
	return (NULL);
}
