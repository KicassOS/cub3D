/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:34:24 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

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
