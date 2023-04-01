/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:32:50 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:40:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"
/*
@MARK
Those functions below are used to get the path value
as char pointer of the map directions.
*/

char	*get_north_path(t_data *data)
{
	t_direction	*tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "NO", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->path);
}

char	*get_south_path(t_data *data)
{
	t_direction	*tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "SO", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->path);
}

char	*get_west_path(t_data *data)
{
	t_direction	*tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "WE", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->path);
}

char	*get_east_path(t_data *data)
{
	t_direction	*tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "EA", ft_strlen(tmp->name)) == SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (tmp->path);
}
