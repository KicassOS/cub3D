/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:46:19 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/29 07:10:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

#define SPEED 0.05f
#define HITBOX	0.1f

static void	ft_move_forward(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->camera.dirX * HITBOX)] != WALL)
			data->player.x += data->camera.dirX * SPEED;
	if (data->map[(int)(data->player.y - data->camera.dirY * HITBOX)]
		[(int)(data->player.x)] != WALL)
			data->player.y -= data->camera.dirY * SPEED;
}

static void	ft_move_back(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->camera.dirX * HITBOX)] != WALL)
		data->player.x -= data->camera.dirX * SPEED;
	if (data->map[(int)(data->player.y + data->camera.dirY * HITBOX)]
		[(int)(data->player.x)] != WALL)
		data->player.y += data->camera.dirY * SPEED;
}

static void	ft_move_left(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->camera.dirY * HITBOX)] != WALL)
		data->player.x -= data->camera.dirY * SPEED;
	if (data->map[(int)(data->player.y - data->camera.dirX * HITBOX)]
		[(int)(data->player.x)] != WALL)
			data->player.y -= data->camera.dirX * SPEED;
}

static void	ft_move_right(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->camera.dirY * HITBOX)] != WALL)
		data->player.x += data->camera.dirY * SPEED;
	if (data->map[(int)(data->player.y + data->camera.dirX * HITBOX)]
		[(int)(data->player.x)] != WALL)
		data->player.y += data->camera.dirX * SPEED;
}

void	ft_move_player(t_data *data)
{
	if (data->keys_pressed.w_pressed == true)
		ft_move_forward(data);
	if (data->keys_pressed.a_pressed == true)
		ft_move_left(data);
	if (data->keys_pressed.s_pressed == true)
		ft_move_back(data);
	if (data->keys_pressed.d_pressed == true)
		ft_move_right(data);
}
