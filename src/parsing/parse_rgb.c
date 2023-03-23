/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:57:16 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/09 18:53:23 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

int check_coma(char *rgb)
{
    int nb_coma;

    if (!rgb)
        return (FAILURE);
    nb_coma = 0;
    while (*rgb)
    {
        if (*rgb == ',')
            nb_coma++;
        rgb++;
    }
    if (nb_coma != 2)
        return (FAILURE);
    return (SUCCESS);
}

int is_valid_rgb(char **rgb)
{
    if (!rgb)
        return (FAILURE);
    if (is_digit_str(rgb[0]) != SUCCESS)
        return (FAILURE);
    if (!(ft_atoi(rgb[0]) >= 0 && ft_atoi(rgb[0]) <= 255))
        return (FAILURE);
    if (is_digit_str(rgb[1]) != SUCCESS)
        return (FAILURE);
    if (!(ft_atoi(rgb[1]) >= 0 && ft_atoi(rgb[1]) <= 255))
        return (FAILURE);
    if (is_digit_str(rgb[2]) != SUCCESS)
        return (FAILURE);
    if (!(ft_atoi(rgb[2]) >= 0 && ft_atoi(rgb[2]) <= 255))
        return (FAILURE);
    return (SUCCESS);
}

int is_param_rgb(t_data *data, char *path)
{
    char **rgb;

    if (!path)
        return (FAILURE);
    if (check_coma(path)!= SUCCESS)
        return (FAILURE);
    rgb = ft_split(data, path, ',');
    if (!rgb)
        return (error_handler(data, MALLOC_ERROR));
    if (array_size(rgb) != 3)
        return (FAILURE);
    if (is_valid_rgb(rgb) != SUCCESS)
        return (FAILURE);
    return (SUCCESS);
}