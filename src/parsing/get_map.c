/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:50:18 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/13 11:12:24 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

static
int is_valid_element(t_data *data, char c)
{
    if (c == '1' || c == '0')
        return (SUCCESS);
    if (c == ' ' || (c >= '\a' && c <= '\r'))
        return (SUCCESS);
    if (c == 'N' ||  c == 'E' || c == 'S' || c == 'W')
        return (SUCCESS);
    return (error_handler(data, MAP_ERROR));
}

int set_map_size(t_data *data)
{
    char **map;
    unsigned int index;
    
    data->map_size = 0;
    if (!data->file_arr)
        return (INVALID_VALUE);
    index = data->last_params_line;
    map = data->file_arr;
    while (map[index])
    {
        index++;
    }
    data->map_size = index - data->last_params_line;
    return (SUCCESS);
}

static
void requirement_map_loop(t_data *data, char *map, unsigned int line ,int *counter)
{
    check_wall(data, map);
    if (line == data->map_size && check_only_one(data, map) != SUCCESS)
        error_handler(data, MAP_ERROR);
    while (*map && (*map == ' ' || (*map >= '\a' && *map <= '\r')))
        map++;
    while (*map)
    {
        is_valid_element(data, *map);
        if (is_floor(*map) == SUCCESS)
            counter[0]++;
        if (is_position(*map) == SUCCESS)
            counter[1]++;
        map++;
    }
}

int requirement_map_checker(t_data *data)
{
    char **map;
    unsigned int index;
    int counter[2];
    unsigned int line;

    counter[0] = 0;
    counter[1] = 0;
    line = 0;
    if (!data->file_arr)
        return (INVALID_VALUE);
    index = data->last_params_line;
    map = data->file_arr;
    if (check_only_one(data, map[index]) != SUCCESS)
        error_handler(data, MAP_ERROR);
    while (map[index])
    {
        requirement_map_loop(data, map[index], line++, counter);
        index++;
    }
    if (counter[0] == 0)
        error_handler(data, MAP_ERROR);
    if (counter[1] != 1)
        error_handler(data, MAP_ERROR);
    return (SUCCESS);
}


int check_only_one(t_data *data, char *line)
{
    int i;

    i = 0;
    if (!line)
        error_handler(data, INVALID_VALUE);
    while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
        i++;
    if (line[i] == '\0')
        return (FAILURE);
    while(line[i])
    {
        while (line[i] && (line[i] == ' ' || line[i] == '\t'))
            i++;
        if (is_one(line[i]) != SUCCESS)
          return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

int check_wall(t_data *data, char *line)
{
    int len;

    len = ft_strlen(line);
      if (!line)
        error_handler(data, INVALID_VALUE);
    if (line[len - 1] != '1')
        error_handler(data, MAP_ERROR);
    while (*line && (*line == ' ' || (*line >= '\a' && *line <= '\r')))
        line++;
    if (*line != '1')
        error_handler(data, MAP_ERROR);
    return (SUCCESS);
}

int get_line_width(char **map, unsigned int index)
{
    if (!map)
        return (FAILURE);
    int size = ft_strlen(map[index]);
    return (size);
}

static
int check_is_space(t_data *data, char **map, unsigned int index, int j)
{
    int width;

    width = get_line_width(map, index);
    if (width == FAILURE)
        return (FAILURE);
    if (j + 1 >= width || index + 1 >= data->map_size)
        error_handler(data, MAP_ERROR);
    if ((map[index][j + 1] == ' ' || (map[index][j + 1] >= '\a' && map[index][j + 1] <= '\r')))
        error_handler(data, MAP_ERROR);
    if ((map[index][j - 1] == ' ' || (map[index][j - 1] >= '\a' && map[index][j - 1] <= '\r')))
        error_handler(data, MAP_ERROR);
    if ((map[index + 1][j] == ' ' || (map[index + 1][j] >= '\a' && map[index + 1][j] <= '\r')))
        error_handler(data, MAP_ERROR);
    if ((map[index - 1][j] == ' ' || (map[index - 1][j] >= '\a' && map[index - 1][j] <= '\r')))
        error_handler(data, MAP_ERROR);
    return (SUCCESS);
}

int is_surrounded_by_space(t_data *data)
{
    char **map;
    unsigned int index;
    int j;
    
    j = 0;
    index = 0;
    if (!data->map)
        return (INVALID_VALUE);
    map = data->map;
    while (index < data->map_size)
    {
        j = 0;
        while (map[index][j])
        {
            if (map[index][j] == '0')
               check_is_space(data, map, index, j);
            if (map[index][j] == 'N')
               check_is_space(data, map, index, j);
            if (map[index][j] == 'E')
               check_is_space(data, map, index, j);
            if (map[index][j] == 'A')
               check_is_space(data, map, index, j);
            if (map[index][j] == 'W')
                check_is_space(data, map, index, j);
            j++;
        }
        index++;
    }
    return (SUCCESS);
}

int fill_map(t_data *data)
{
    int index;
    char **file_map;
    int j;

    j = 0;
    file_map = data->file_arr;
    index = data->last_params_line;
    data->map = ft_malloc(data , sizeof(char *) * (data->map_size + 1));
    if (!data->map)
        return (MALLOC_ERROR);
    while (file_map[index])
    {
        data->map[j] = ft_strdup(data, file_map[index]);
        if (!data->map[j])
            error_handler(data, MALLOC_ERROR);
        j++;
        index++;
    }
    data->map[j] = NULL;
    return (SUCCESS);
}

void get_map(t_data *data)
{
    if (set_map_size(data))
        error_handler(data, MAP_ERROR);
    requirement_map_checker(data);
    fill_map(data);
    is_surrounded_by_space(data); 
}