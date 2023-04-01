/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parsed_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:51 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:46 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

static int	sort_and_add_params(t_data *data)
{
	char	**array_params;

	array_params = ft_split(data, data->params->content, ' ');
	if (!array_params)
		return (error_handler(data, MALLOC_ERROR));
	if (is_param_path(array_params[1]) == SUCCESS)
	{
		if (add_direction_params(&data, array_params[0],
				array_params[1]) != SUCCESS)
			return (error_handler(data, MALLOC_ERROR));
		return (SUCCESS);
	}
	if (is_param_rgb(data, array_params[1]) == SUCCESS)
	{
		if (add_node_colors(&data, array_params[0], array_params[1]) != SUCCESS)
			return (error_handler(data, MALLOC_ERROR));
		return (SUCCESS);
	}
	return (error_handler(data, PARAMS_ERROR));
}

int	fill_parsed_params(t_data *data)
{
	if (!data->params)
		return (FAILURE);
	while (data->params)
	{
		if (check_empty_line(data->params->content) == SUCCESS)
		{
			data->params = data->params->next;
			continue ;
		}
		if (sort_and_add_params(data) != SUCCESS)
			return (FAILURE);
		data->params = data->params->next;
	}
	return (SUCCESS);
}
