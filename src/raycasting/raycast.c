/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:34:19 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/29 08:15:38 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

void	ft_init_raycaster(t_data *data, t_raycaster *rayc, int x)
{
	rc->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	rc->raydir_x = data->camera.dir_x + data->camera.plane_x * rc->camera_x;
	rc->raydir_y = data->camera.dir_y + data->camera.plane_y * rc->camera_x;
	rc->map_x = (int)data->player.x;
	rc->map_y = (int)data->player.y;
	rc->deltadist_x = fabs(1 / rc->raydir_x);
	rc->deltadist_y = fabs(1 / rc->raydir_y);
	rc->hit = 0;
}

void	ft_init_rays(t_data *data, t_raycaster *rayc)
{
	if (rayc->raydir_x < 0)
	{
		rayc->step_x = -1;
		rayc->sidedist_x = (data->player.x - rayc->map_x) * rayc->deltadist_x;
	}
	else
	{
		rayc->step_x = 1;
		rayc->sidedist_x = (rayc->map_x + 1.0f - data->player.x)
			* rayc->deltadist_x;
	}
	if (rayc->raydir_y > 0)
	{
		rayc->step_y = -1;
		rayc->sidedist_y = (data->player.y - rayc->map_y) * rayc->deltadist_y;
	}
	else
	{
		rayc->step_y = 1;
		rayc->sidedist_y = (rayc->map_y + 1.0f - data->player.y)
			* rayc->deltadist_y;
	}
}

void	ft_distance_to_wall(char **map, t_raycaster *rayc)
{
	while (!rayc->hit)
	{
		if (rayc->sidedist_x < rayc->sidedist_y)
		{
			rayc->sidedist_x += rayc->deltadist_x;
			rayc->map_x += rayc->step_x;
			rayc->side = VERTICAL;
		}
		else
		{
			rayc->sidedist_y += rayc->deltadist_y;
			rayc->map_y += rayc->step_y;
			rayc->side = HORIZONTAL;
		}
		if (map[rayc->map_y][rayc->map_x] == WALL)
			rayc->hit = true;
	}
}

void	ft_get_wall_height(t_raycaster *rayc)
{
	if (rayc->side == VERTICAL)
		rayc->distance = rayc->sidedist_x - rayc->deltadist_x;
	else
		rayc->distance = rayc->sidedist_y - rayc->deltadist_y;
	rayc->line_height = (int)(SCREEN_HEIGHT / rayc->distance);
	rayc->draw_start = -rayc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rayc->draw_start < 0)
		rayc->draw_start = 0;
	rayc->draw_end = rayc->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rayc->draw_end >= SCREEN_HEIGHT)
		rayc->draw_end = SCREEN_HEIGHT - 1;
}

void	ft_get_wall_pixel(t_data *data, t_raycaster *rayc)
{
	if (rayc->side == VERTICAL)
		rayc->wall_x = (int)data->player.y + rayc->distance * rayc->raydir_y;
	else
		rayc->wall_x = (int)data->player.x + rayc->distance * rayc->raydir_x;
	rayc->wall_x -= floor(rayc->wall_x);
	rayc->tex_x = (int)(rayc->wall_x * (double)TEXTURE_WIDTH);
	if (rayc->side == VERTICAL && rayc->raydir_x > 0)
		rayc->tex_x = TEXTURE_WIDTH - rayc->tex_x - 1;
	if (rayc->side == HORIZONTAL && rayc->raydir_y < 0)
		rayc->tex_x = TEXTURE_WIDTH - rayc->tex_x - 1;
	rayc->step = 1.0 * TEXTURE_HEIGHT / rayc->line_height;
	rayc->texPos = (rayc->draw_start - (SCREEN_HEIGHT / 2) \
	+ rayc->line_height / 2) * rayc->step;
}
