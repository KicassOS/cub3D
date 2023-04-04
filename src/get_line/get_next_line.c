/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:40:36 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/04 21:10:22 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

char	*ft_get_line(t_data *data, char *save)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	buffer = ft_malloc(data, sizeof(char) * i + 2);
	if (!buffer)
		error_handler(data, MALLOC_ERROR);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_save(t_data *data, char *save)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free_str(save), NULL);
	buffer = ft_malloc(data, sizeof(char) * (strlen(save) - i + 1));
	if (!buffer)
		error_handler(data, MALLOC_ERROR);
	i++;
	j = 0;
	while (save[i])
		buffer[j++] = save[i++];
	buffer[j] = '\0';
	return (buffer);
}

char	*read_line(t_data *data, int fd, char *save, int *v_read)
{
	char	*buffer;

	buffer = ft_malloc(data, sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		error_handler(data, MALLOC_ERROR);
	*v_read = 1;
	while (!ft_strchr(save, '\n') && *v_read != 0)
	{
		*v_read = read(fd, buffer, BUFFER_SIZE);
		if (*v_read == -1)
			return (NULL);
		buffer[*v_read] = '\0';
		if (*v_read)
			save = ft_strjoin_line(data, save, buffer);
	}
	return (save);
}

char	*get_next_line(t_data *data, int fd)
{
	char		*buffer;
	static char	*save = (char *)0;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(data, fd, save, &ret);
	if (!save)
		return (NULL);
	buffer = ft_get_line(data, save);
	if (!buffer)
		return (NULL);
	save = ft_save(data, save);
	return (buffer);
}
