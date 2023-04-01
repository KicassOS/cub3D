/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:19:17 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

char	*ft_strchr(char *str, int c)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == '\0' && (char)c == '\0')
	{
		return (&str[i]);
	}
	return (NULL);
}
