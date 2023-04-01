/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:53 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	a;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[0] == '\0' || l == NULL)
		return (b);
	while (b[i] != '\0' && i < len)
	{
		a = 0;
		if (l[a] == b[i])
		{
			while (*b && *l && b[i + a] && l[a] == b[i + a] && (i + a < len))
				a++;
			if (l[a] == '\0')
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
