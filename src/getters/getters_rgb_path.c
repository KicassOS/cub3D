/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_rgb_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:32:53 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:42:53 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

/*
@MARK
Those functions below are used to get
the rgb value as char pointer of the map colors.
*/

char	*get_floor_path(t_data *data)
{
	t_colors	*tmp;

	if (data->colors == NULL)
		return (NULL);
	tmp = data->colors;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "F", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->rgb);
}

char	*get_cell_path(t_data *data)
{
	t_colors	*tmp;

	if (data->colors == NULL)
		return (NULL);
	tmp = data->colors;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "C", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->rgb);
}
