/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:26:55 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/03 23:27:35 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	file_to_array(t_data *data, char *file_store)
{
	if (!(file_store))
		return (INVALID_VALUE);
	data->file_arr = ft_split(data, file_store, '\n');
	if (!data->file_arr)
		return (MALLOC_ERROR);
	return (SUCCESS);
}
