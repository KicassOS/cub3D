/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:16:08 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/06 11:31:14 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

static
void malloc_error(t_data *data)
{
    printf("Error\n : Malloc failed !\n");
    ft_free(data);
}


static
void map_error(t_data *data)
{
    printf("Error\n : Invalid map !\n");
    ft_free(data);
}


static
void params_error(t_data *data)
{
    printf("Error\n : wrong description of your map, make sure to have a structure like this : \n"); 
    printf("NO  ./path_to_the_north_texture\n");
    printf("EA  ./path_to_the_east_texture \n");
    printf("SO  ./path_to_the_south_texture\n");
    printf("WE  ./path_to_the_west_texture\n");
    printf("F 225,100,0\nC 255,100,0\n");
    ft_free(data);
}

static
void invalid_file(void)
{
    printf("Error\n : Can't open file, make sure it's a file and not a directory.\n");
}

static
void invalid_value(t_data *data)
{
    printf("Error\n : Try to access to an uninitalize value, program has quit.\n");
    ft_free(data);
}

int error_handler(t_data *data, int error)
{
    if (error == MALLOC_ERROR)
        malloc_error(data);
    else if (error == INVALID_FILE)
        invalid_file();
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