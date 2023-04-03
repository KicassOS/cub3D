/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:48:11 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/03 23:27:32 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	valid_arg(char *arg)
{
	if (!arg)
	{
		ft_putstr_fd("Error\narg is NULL\n", 2);
		exit(FAILURE);
	}
	if (!(ft_strchr(arg, '.')))
	{
		ft_putstr_fd("Error\nFile name must be named as: <filename>.cub\n", \
						2);
		exit(FAILURE);
	}
	if (ft_valid_extension(arg) == false)
	{
		ft_putstr_fd("Error\nFile name must be named as: <filename>.cub\n", \
						2);
		exit(FAILURE);
	}
	return (SUCCESS);
}

int	check_only_one_not_parsed(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (!line)
		error_handler(data, INVALID_VALUE);
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	if (line[i] == '\0')
		return (FAILURE);
	while (line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (is_one(line[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

char	*get_right_line(t_data *data, char *file_line, char *tmp, \
		int *detect)
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

void	ft_init_cub_to_str(char *file, int *fd, int *detect, t_data *data)
{
	*detect = 0;
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		error_handler(data, INVALID_FILE);
}

char	*cub_to_str(t_data *data, char *file)
{
	char	*file_store;
	char	*tmp;
	int		detect;
	int		fd;

	ft_init_cub_to_str(file, &fd, &detect, data);
	file_store = NULL;
	tmp = get_next_line(fd);
	while ((tmp))
	{
		file_store = get_right_line(data, file_store, tmp, &detect);
		free_str(tmp);
		tmp = get_next_line(fd);
	}
	free_str(tmp);
	get_next_line(-1);
	close(fd);
	return (file_store);
}
