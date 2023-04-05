/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:21:43 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/05 12:35:10 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	file_to_array(t_data *data, char *file_store)
{
	int	i;

	i = 0;
	if (!(file_store))
		return (INVALID_VALUE);
	data->file_arr = ft_split(data, file_store, '\n');
	while (file_store[i])
		i++;
	if (file_store[i - 1] == '\n')
		error_handler(data, MAP_ERROR);
	if (!data->file_arr)
		return (MALLOC_ERROR);
	return (SUCCESS);
}
