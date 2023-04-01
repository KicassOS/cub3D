/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:16:08 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:41:32 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"
/*
@MARK
This function is almost called everywhere in the program, it helps to
catch whereas the error occur and quit the program properly. 
*/

int	error_handler(t_data *data, int error)
{
	if (error == MALLOC_ERROR)
		malloc_error(data);
	else if (error == INVALID_FILE)
		invalid_file(data);
	else if (error == MAP_ERROR)
		map_error(data);
	else if (error == PARAMS_ERROR)
		params_error(data);
	else if (error == INVALID_VALUE)
		invalid_value(data);
	else
		return (SUCCESS);
	exit(FAILURE);
}
