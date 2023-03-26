/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:58 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/10 13:46:46 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

static
int check_legit_path(char *path)
{
    int checker;
    
    checker = open(path, O_RDONLY);
    if (checker < 0)
        return (FAILURE);
    close(checker);
    return (SUCCESS);
}

int is_param_path(char *path)
{
    if (!path)
        return (FAILURE);
    if (ft_strlen(path) <= 2)
        return (FAILURE);
    if (path[0] != '.' && path[1] != '/')
        return (FAILURE);
    if (check_legit_path(path) != SUCCESS)
        return (FAILURE);
    return (SUCCESS);
}

static
int is_param_name(t_data *data, char *name)
{
    if (!name)
        return (FAILURE);
    if (ft_strlen(name) == 1)
    {
        update_requirement_params(data, name);
        if (ft_strncmp(name, "F", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
        if (ft_strncmp(name, "C", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
    }
    if (ft_strlen(name) == 2)
    {
        update_requirement_params(data, name);
        if (ft_strncmp(name, "NO", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
        if (ft_strncmp(name, "SO", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
        if (ft_strncmp(name, "WE", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
        if (ft_strncmp(name, "EA", ft_strlen(name)) == SUCCESS)
            return (SUCCESS);
    }
    return (error_handler(data, PARAMS_ERROR));
}

static
int is_valid_param(t_data *data, char *line)
{
    char **array_line;
    
    if (!line)
        return (FAILURE);
    array_line = ft_split(data, line, ' ');
    if (!array_line)
        return(error_handler(data, MALLOC_ERROR)); // MALLOC FAILURE
    if (is_param_name(data, array_line[0]) != SUCCESS)
        return (error_handler(data, PARAMS_ERROR)); // PARSE WITH MALLOC
    if (is_param_path(array_line[1]) == SUCCESS)
        return(SUCCESS);
    if (is_param_rgb(data, array_line[1]) == SUCCESS)
        return (SUCCESS);
    return (error_handler(data, PARAMS_ERROR)); // PARSE WITH MALLOC
}

int parse_node_params(t_data *data)
{
    t_params *params;
    int     params_nb;

    params_nb = 0;
    params = data->params;
    set_requirement(data);
    while (params)
    {
        if (check_empty_line(params->content) == SUCCESS)
        {
            params = params->next;
            continue ;
        }
        if (is_valid_param(data, params->content) != SUCCESS)
            error_handler(data, PARAMS_ERROR);
        if (params_nb > 5)
            error_handler(data, PARAMS_ERROR);
        params_nb++;
        params = params->next;
    }
    if (params_nb != 6)
        error_handler(data, PARAMS_ERROR); // PARSE WITH MALLOC
    if (requirement_params_checker(data) != SUCCESS)
        error_handler(data, PARAMS_ERROR); // PARSE WITH MALLOC
    return (SUCCESS);
}