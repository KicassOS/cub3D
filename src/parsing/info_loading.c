/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_loading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 05:41:51 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/01 21:10:35 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

void	ft_load_player_orientation(t_data *data)
{
	int	i;
	int	j;

	if (!data || data->map == NULL)
		ft_error_free_exit(data, "Error:\nMap is NULL in load_orientation\n");
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (is_position((data->map[i][j])))
				data->player.orientation = data->map[i][j];
			j++;
		}
		i++;
	}
		printf("DELETE THESE 2 PRINTF\n");
	printf("orientation: %c\n", data->player.orientation);
}

void	ft_load_player_position(t_data *data)
{
	int	i;
	int	j;

	if (!data || data->map == NULL)
		ft_error_free_exit(data, "Error:\nMap is NULL in load_position\n");
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (is_position(data->map[i][j]))
			{
				data->player.x = (double)j + 0.5;
				data->player.y = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
		printf("DELETE THESE 2 PRINTF\n");
	printf("position: x = %f; y = %f\n", data->player.x, data->player.y);
}

void	ft_load_tex(t_img *img, char *path, int *size, t_data *data)
{
	img->ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, size, size);
	if (!(img->ptr))
		ft_error_free_exit(data, "Error:\nCould not convert xpm file \
		to image\n");
	img->address = mlx_get_data_addr(img->ptr, &(img->bpp), \
	&(img->line_length), &(img->endianness));
	if (!(img->address))
		ft_error_free_exit(data, "Error:\nCould not get address of image\n");
}

void	ft_load_textures(t_data *data)
{
	char	*north_path;
	char	*east_path;
	char	*south_path;
	char	*west_path;

	north_path = ft_get_north_path(data);
	east_path = ft_get_east_path(data);
	south_path = ft_get_south_path(data);
	west_path = ft_get_west_path(data);
	if (!north_path || !east_path || !south_path || !west_path)
		ft_error_free_exit(data, "Error:\nCould not get texture paths\n");
	ft_load_tex(&(data->textures.north_img), north_path, \
	&(data->tex_size), data);
	ft_load_tex(&(data->textures.east_img), east_path, \
	&(data->tex_size), data);
	ft_load_tex(&(data->textures.south_img), south_path, \
	&(data->tex_size), data);
	ft_load_tex(&(data->textures.west_img), west_path, \
	&(data->tex_size), data);
}

void	ft_load_floor_ceiling(t_data *data)
{
	char	**floor_rgb;
	char	**sky_rgb;
	int		i;

	floor_rgb = ft_split_str(ft_get_floor_path(data), ',');
	sky_rgb = ft_split_str(ft_get_ceil_path(data), ',');
	if (!floor_rgb || !sky_rgb)
		ft_error_free_exit(data, "Error:\nCould not get floor/ceiling path\n");
	data->textures.sky_colors[0] = ft_atoi(sky_rgb[0]);
	data->textures.sky_colors[1] = ft_atoi(sky_rgb[1]);
	data->textures.sky_colors[2] = ft_atoi(sky_rgb[2]);
	data->textures.floor_colors[0] = ft_atoi(floor_rgb[0]);
	data->textures.floor_colors[1] = ft_atoi(floor_rgb[1]);
	data->textures.floor_colors[2] = ft_atoi(floor_rgb[2]);
	i = -1;
	while (++i < 3)
		free(floor_rgb[i]);
	free(floor_rgb);
	i = -1;
	while (++i < 3)
		free(sky_rgb[i]);
	free(sky_rgb);
	
	for (int j = 0; j < 3; j++)
		printf("skycolors[%d] = %d, floor_colors[%d] = %d\n", j,data->textures.sky_colors[j], j, data->textures.floor_colors[j]);
}
