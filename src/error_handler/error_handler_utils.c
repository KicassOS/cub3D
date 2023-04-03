/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:35:51 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/03 06:19:59 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

void	malloc_error(t_data *data)
{
	printf("Error\nMalloc failed !\n");
	ft_free_exit(data);
}

void	map_error(t_data *data)
{
	printf("Error\nInvalid map !\n");
	ft_free_exit(data);
}

void	params_error(t_data *data)
{
	printf("Error\nWrong description of your map, \
			make sure to have a structure like this : \n");
	printf("NO  ./path_to_the_north_texture\n");
	printf("EA  ./path_to_the_east_texture \n");
	printf("SO  ./path_to_the_south_texture\n");
	printf("WE  ./path_to_the_west_texture\n");
	printf("F 225,100,0\nC 255,100,0\n");
	ft_free_exit(data);
}

void	invalid_file(t_data *data)
{
	printf("Error\nCan't open file, \
			make sure it's a file and not a directory.\n");
	ft_free_exit(data);
}

void	invalid_value(t_data *data)
{
	printf("Error\nTry to access to an uninitalize value, \
			program has quit.\n");
	ft_free_exit(data);
}
