/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:15:19 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	is_not_params(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (!line)
		error_handler(data, INVALID_VALUE);
	while (line[i] == ' ' || (line[i] >= '\a' && line[i] <= '\r'))
		i++;
	if (line[i] == '1')
		return (FAILURE);
	if (line[i] == '0')
		return (FAILURE);
	return (SUCCESS);
}

int	fill_params(t_data *data)
{
	if (!data->file_arr)
		return (INVALID_VALUE);
	data->last_params_line = 0;
	while (is_not_params(data,
			data->file_arr[data->last_params_line]) == SUCCESS)
	{
		if (add_node_params(&data,
				data->file_arr[data->last_params_line]) != SUCCESS)
			return (MALLOC_ERROR);
		data->last_params_line++;
	}
	return (SUCCESS);
}
