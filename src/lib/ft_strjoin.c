/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:50:00 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/03 23:22:02 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

char	*ft_strjoin(t_data *data, char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	j = 0;
	k = 0;
	if (!s2)
		return (NULL);
	res = ft_malloc(data, sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		error_handler(data, MALLOC_ERROR);
	while (s1 && s1[i])
		res[k++] = s1[i++];
	while (s2[j])
		res[k++] = s2[j++];
	res[k] = '\0';
	return (res);
}
