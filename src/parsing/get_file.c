/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:25:14 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:45:04 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	get_file(t_data *data, char *file)
{
	int	get_value;

	get_value = 0;
	if (valid_arg(file) != SUCCESS)
		return (FAILURE);
	get_value = file_to_array(data, cub_to_str(data, file));
	error_handler(data, get_value);
	get_value = fill_params(data);
	error_handler(data, get_value);
	get_value = parse_node_params(data);
	error_handler(data, get_value);
	get_value = fill_parsed_params(data);
	error_handler(data, get_value);
	return (SUCCESS);
}
