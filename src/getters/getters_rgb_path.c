#include "../includes/define.h"

char *get_floor_path(t_data *data)
{
    t_colors  *tmp;

	if (data->colors == NULL)
		return (NULL);
	tmp = data->colors;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "F", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->rgb);
}

char *get_cell_path(t_data *data)
{
    t_colors  *tmp;

	if (data->colors == NULL)
		return (NULL);
	tmp = data->colors;
	while (tmp)
	{
        if (ft_strncmp(tmp->name, "C", ft_strlen(tmp->name)) == SUCCESS)
            break ;
		tmp = tmp->next;
	}
    return (tmp->rgb);
}