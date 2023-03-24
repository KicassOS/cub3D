#include "../includes/define.h"

char *get_north_path(t_data *data)
{
    t_direction  *tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "NO", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->path);
}

char *get_south_path(t_data *data)
{
    t_direction  *tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "SO", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->path);
}

char *get_west_path(t_data *data)
{
    t_direction  *tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "WE", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->path);
}

char *get_east_path(t_data *data)
{
    t_direction  *tmp;

	if (data->direction == NULL)
		return (NULL);
	tmp = data->direction;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "EA", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->path);
}