/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps_utilspp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:48:16 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/09 05:50:30 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

void	check_map_cell(t_data *data, char **map, unsigned int index, int j)
{
	if (map[index][j] == '0' || map[index][j] == 'N' ||
		map[index][j] == 'E' || map[index][j] == 'S' ||
		map[index][j] == 'W')
	{
		check_is_space(data, map, index, j);
	}
}

int	iterate_map(t_data *data, char **map)
{
	unsigned int	index;
	int				j;

	index = 0;
	if (!map)
		return (INVALID_VALUE);
	while (index < data->map_size)
	{
		j = 0;
		while (map[index][j])
		{
			check_map_cell(data, map, index, j);
			j++;
		}
		index++;
	}
	return (SUCCESS);
}
