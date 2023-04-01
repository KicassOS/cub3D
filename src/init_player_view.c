/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:57:54 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/01 08:19:53 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

static void	north_start(t_data *data)
{
	data->camera.plane_x = 0.66;
	data->camera.plane_y = 0;
	data->camera.dir_x = 0.0f;
	data->camera.dir_y = 1.0f;
}

static void	east_start(t_data *data)
{
	data->camera.plane_x = 0;
	data->camera.plane_y = -0.66;
	data->camera.dir_x = 1.0f;
	data->camera.dir_y = 0.0f;
}

static void	south_start(t_data *data)
{
	data->camera.plane_x = -0.66;
	data->camera.plane_y = 0;
	data->camera.dir_x = 0.0f;
	data->camera.dir_y = -1.0f;
}

static void	west_start(t_data *data)
{
	data->camera.plane_x = 0;
	data->camera.plane_y = 0.66;
	data->camera.dir_x = -1.0f;
	data->camera.dir_y = 0.0f;
}

void	ft_init_player_view(t_data *data)
{
	if (data->player.orientation == NORTH)
		north_start(data);
	if (data->player.orientation == EAST)
		east_start(data);
	if (data->player.orientation == SOUTH)
		south_start(data);
	if (data->player.orientation == WEST)
		west_start(data);
}
