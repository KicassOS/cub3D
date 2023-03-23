/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:41:08 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/09 13:50:07 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

int is_position(char c)
{
     if (c == 'N' ||  c == 'E' || c == 'S' || c == 'W')
        return (SUCCESS);
    return (FAILURE);
}

int is_floor(char c)
{
    if (c == '0')
        return (SUCCESS);
    return (FAILURE);
}

int is_one(char c)
{
    if (c == '1')
        return (SUCCESS);
    return (FAILURE);
}

int is_digit_str(char *str)
{
    while (*str)
    {
        if (!(ft_isdigit(*str)))
            return (FAILURE);
        str++;
    }
    return (SUCCESS);
}

int array_size(char **array)
{
    int i;
    
    i = 0;
    if (!array)
        return (FAILURE);
    while (array[i])
        i++;
    return (i);
}

int check_empty_line(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (FAILURE);
    while (line[i])
    {
        if (!(line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
            return (FAILURE);
        i++;     
    }
    return (SUCCESS);
}