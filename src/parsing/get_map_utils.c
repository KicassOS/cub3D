/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:00:55 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:45:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	set_map_size(t_data *data)
{
	char			**map;
	unsigned int	index;

	data->map_size = 0;
	if (!data->file_arr)
		return (INVALID_VALUE);
	index = data->last_params_line;
	map = data->file_arr;
	while (map[index])
		index++;
	data->map_size = index - data->last_params_line;
	return (SUCCESS);
}

int	is_valid_element(t_data *data, char c)
{
	if (c == '1' || c == '0')
		return (SUCCESS);
	if (c == ' ' || (c >= '\a' && c <= '\r'))
		return (SUCCESS);
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (SUCCESS);
	return (error_handler(data, MAP_ERROR));
}

void	requirement_map_loop(t_data *data, char *map, unsigned int line,
		int *counter)
{
	check_wall(data, map);
	if (line == data->map_size && check_only_one(data, map) != SUCCESS)
		error_handler(data, MAP_ERROR);
	while (*map && (*map == ' ' || (*map >= '\a' && *map <= '\r')))
		map++;
	while (*map)
	{
		is_valid_element(data, *map);
		if (is_floor(*map) == SUCCESS)
			counter[0]++;
		if (is_position(*map) == SUCCESS)
			counter[1]++;
		map++;
	}
}

int	check_only_one(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (!line)
		error_handler(data, INVALID_VALUE);
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	if (line[i] == '\0')
		return (FAILURE);
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (is_one(line[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_is_space(t_data *data, char **map, unsigned int index, int j)
{
	int	width;

	if (!map)
		return (FAILURE);
	width = ft_strlen(map[index]);
	if (width == 0)
		return (FAILURE);
	if (j + 1 >= width || index + 1 >= data->map_size)
		error_handler(data, MAP_ERROR);
	if ((map[index][j + 1] == ' ' || (map[index][j + 1] >= '\a' && map[index][j \
				+ 1] <= '\r')))
		error_handler(data, MAP_ERROR);
	if ((map[index][j - 1] == ' ' || (map[index][j - 1] >= '\a' && map[index][j \
				- 1] <= '\r')))
		error_handler(data, MAP_ERROR);
	if ((map[index + 1][j] == ' ' || (map[index + 1][j] >= '\a' && map[index \
				+ 1][j] <= '\r')))
		error_handler(data, MAP_ERROR);
	if ((map[index - 1][j] == ' ' || (map[index - 1][j] >= '\a' && map[index \
				- 1][j] <= '\r')))
		error_handler(data, MAP_ERROR);
	return (SUCCESS);
}
