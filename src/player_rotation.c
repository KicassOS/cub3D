/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:39:59 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/03 08:25:34 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

#define ROTSPEED 0.05f

void	ft_rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->camera.dir_x;
	data->camera.dir_x = data->camera.dir_x * cos(-ROTSPEED) - data->camera.dir_y * sin(-ROTSPEED);
	data->camera.dir_y = old_dir_x * sin(-ROTSPEED) + data->camera.dir_y * cos(-ROTSPEED);
	old_plane_x = data->camera.plane_x;
	data->camera.plane_x = data->camera.plane_x * cos(-ROTSPEED) - data->camera.plane_y * sin(-ROTSPEED);
	data->camera.plane_y = old_plane_x * sin(-ROTSPEED) + data->camera.plane_y * cos(-ROTSPEED);
}

void	ft_rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	//both camera direction and camera plane must be rotated
	old_dir_x = data->camera.dir_x;
	data->camera.dir_x = data->camera.dir_x * cos(ROTSPEED) - data->camera.dir_y * sin(ROTSPEED);
	data->camera.dir_y = old_dir_x * sin(ROTSPEED) + data->camera.dir_y * cos(ROTSPEED);
	old_plane_x = data->camera.plane_x;
	data->camera.plane_x = data->camera.plane_x * cos(ROTSPEED) - data->camera.plane_y * sin(ROTSPEED);
	data->camera.plane_y = old_plane_x * sin(ROTSPEED) + data->camera.plane_y * cos(ROTSPEED);
}

void	ft_rotate_player(t_data *data)
{
	if (data->keys_pressed.rarr_pressed == true)
		ft_rotate_right(data);
	if (data->keys_pressed.larr_pressed == true)
		ft_rotate_left(data);
}
