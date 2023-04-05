/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:50:18 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/05 13:03:26 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	requirement_map_checker(t_data *data)
{
	char			**map;
	unsigned int	index;
	int				counter;
	unsigned int	line;

	counter = 0;
	line = 0;
	if (!data->file_arr)
		return (INVALID_VALUE);
	index = data->last_params_line;
	map = data->file_arr;
	if (check_only_one(data, map[index]) != SUCCESS)
		error_handler(data, MAP_ERROR);
	while (map[index])
	{
		requirement_map_loop(data, map[index], line++, &counter);
		index++;
	}
	if (counter != 1)
		error_handler(data, MAP_ERROR);
	return (SUCCESS);
}

int	check_wall(t_data *data, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (!line)
		error_handler(data, INVALID_VALUE);
	if (line[len - 1] != '1')
		error_handler(data, MAP_ERROR);
	while (*line && (*line == ' ' || (*line >= '\a' && *line <= '\r')))
		line++;
	if (*line != '1')
		error_handler(data, MAP_ERROR);
	return (SUCCESS);
}

int	is_surrounded_by_space(t_data *data)
{
	return (iterate_map(data, data->map));
}

int	fill_map(t_data *data)
{
	int		index;
	char	**file_map;
	int		j;

	j = 0;
	file_map = data->file_arr;
	index = data->last_params_line;
	data->map = ft_malloc(data, sizeof(char *) * (data->map_size + 1));
	if (!data->map)
		return (MALLOC_ERROR);
	while (file_map[index])
	{
		data->map[j] = ft_strdup(data, file_map[index]);
		if (!data->map[j])
			error_handler(data, MALLOC_ERROR);
		j++;
		index++;
	}
	data->map[j] = NULL;
	return (SUCCESS);
}

void	get_map(t_data *data)
{
	if (set_map_size(data))
		error_handler(data, MAP_ERROR);
	requirement_map_checker(data);
	fill_map(data);
	is_surrounded_by_space(data);
}
