/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:25:14 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/10 12:57:08 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

static
int valid_arg(char *arg)
{
	if (!(ft_strchr(arg, '.')))
	{
		ft_putstr_fd("Error :\nfile name must be named as: <filename>.cub\n", 2);
		exit(FAILURE);
	}
	if (ft_strncmp(ft_strchr(arg, '.'), ".cub", 4) != SUCCESS)
	{
		ft_putstr_fd("Error :\nfile name must be named as: <filename>.cub\n", 2);
		exit(FAILURE);
	}
    return (SUCCESS);
}

static
int check_only_one_not_parsed(t_data *data, char *line)
{
    int i;

    i = 0;
    if (!line)
        error_handler(data, INVALID_VALUE);
    while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
        i++;
    if (line[i] == '\0')
        return (FAILURE);
    while(line[i] && line[i] != '\n')
    {
        while (line[i] && line[i] == ' ')
            i++;
        if (is_one(line[i]) != SUCCESS)
          return(FAILURE);
        i++;
    }
    return (SUCCESS);
}

static
char *get_right_line(t_data *data, char *file_line, char *tmp, int *detect)
{
    file_line = ft_strjoin(data, file_line, tmp);
    if (!file_line)
        return (NULL);
    if (check_only_one_not_parsed(data, tmp) == SUCCESS)
        (*detect)++;
    if (*detect > 0)
    {
        if (ft_strlen(tmp) == 1)
            return (free(tmp), NULL);
    }
    return (file_line);
}

static
char *cub_to_str(t_data *data, char *file)
{
    char    *file_store;
    char    *tmp;
    int     detect;
    int     fd;

    tmp = "ok";
    detect = 0;
    file_store = NULL;
    if (!file)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_handler(data, INVALID_FILE);
    while((tmp = get_next_line(fd)))
    {
        if (tmp)
        {
            file_store = get_right_line(data, file_store, tmp, &detect);
            if (!file_store)
                break ;
            free(tmp);
            tmp = NULL;
        }
    }
    get_next_line(-1); // sending a negatif value to my get_next_line in order to free the '\n' 
    close(fd);
    return (file_store);
}

static
int file_to_array(t_data *data, char *file_store)
{
    if (!(file_store))
        return (INVALID_VALUE);
    data->file_arr = ft_split(data, file_store, '\n');
    if (!data->file_arr)
        return (MALLOC_ERROR); // MALLOC FAILURE
    return (SUCCESS);
}

int get_file(t_data *data, char *file)
{
    int get_value;

    get_value = 0;
    if(valid_arg(file) != SUCCESS)
        return (FAILURE);
    get_value = file_to_array(data, cub_to_str(data, file));
    error_handler(data, get_value);
    get_value = fill_params(data);
    error_handler(data, get_value);
    get_value = parse_node_params(data);
    error_handler(data, get_value);
    get_value = fill_parsed_params(data);
    error_handler(data, get_value);
    return (SUCCESS);
}