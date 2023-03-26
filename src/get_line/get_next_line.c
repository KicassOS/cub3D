/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:40:36 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 17:55:32 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	buffer = malloc(sizeof(char) * i + 2);
	if (!buffer)
		return (NULL);
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

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free_str(save), NULL);
	buffer = malloc(sizeof(char) * (strlen(save) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		buffer[j++] = save[i++];
	buffer[j] = '\0';
	free_str(save);
	return (buffer);
}

char	*read_line(int fd, char *save, int *v_read)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*v_read = 1;
	while (!ft_strchr(save, '\n') && *v_read != 0)
	{
		*v_read = read(fd, buffer, BUFFER_SIZE);
		if (*v_read == -1)
		{
			free_str(buffer);
			return (NULL);
		}
		buffer[*v_read] = '\0';
		if (*v_read)
			save = ft_strjoin_line(save, buffer);
	}
	free_str(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save = (char *)0;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_str(save);
		return (NULL);
	}
	save = read_line(fd, save, &ret);
	if (!save)
		return (NULL);
	buffer = ft_get_line(save);
	if (!buffer)
		return (free_str(buffer), NULL);
	save = ft_save(save);
	if (!ret)
		free_str(save);
	return (buffer);
}
