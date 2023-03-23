/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_requirement.params.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:00:15 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/03 15:12:19 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

int requirement_params_checker(t_data *data)
{
    if (data->params_required.north != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    if (data->params_required.south != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    if (data->params_required.west != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    if (data->params_required.east != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    if (data->params_required.floor != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    if (data->params_required.cell != 1)
        return (PARAMS_ERROR); // PARAMS MAP ERROR
    return (SUCCESS);
}

void set_requirement(t_data *data)
{
    data->params_required.north = 0;
    data->params_required.south = 0;
    data->params_required.west = 0;
    data->params_required.east = 0;
    data->params_required.floor = 0;
    data->params_required.cell = 0;
}

void update_requirement_params(t_data *data, char *name)
{
    if (ft_strlen(name) == 1)
    {
        if (ft_strncmp(name, "F", ft_strlen(name)) == SUCCESS)
            data->params_required.floor++;
        if (ft_strncmp(name, "C", ft_strlen(name)) == SUCCESS)
            data->params_required.cell++;
    }
    if (ft_strlen(name) == 2)
    {
        if (ft_strncmp(name, "NO", ft_strlen(name)) == SUCCESS)
            data->params_required.north++;
        if (ft_strncmp(name, "SO", ft_strlen(name)) == SUCCESS)
            data->params_required.south++;
        if (ft_strncmp(name, "WE", ft_strlen(name)) == SUCCESS)
            data->params_required.west++;
        if (ft_strncmp(name, "EA", ft_strlen(name)) == SUCCESS)
            data->params_required.east++;
    }    
}
