/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:38:39 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/29 09:45:08 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

void	ft_init_textures(t_data *data)
{
	data->textures.north_img.ptr = NULL;
	data->textures.north_img.address = NULL;
	data->textures.north_img.bpp = 0;
	data->textures.north_img.line_length = 0;
	data->textures.north_img.endianness = 0;
	data->textures.east_img.ptr = NULL;
	data->textures.east_img.address = NULL;
	data->textures.east_img.bpp = 0;
	data->textures.east_img.line_length = 0;
	data->textures.east_img.endianness = 0;
	data->textures.south_img.ptr = NULL;
	data->textures.south_img.address = NULL;
	data->textures.south_img.bpp = 0;
	data->textures.south_img.line_length = 0;
	data->textures.south_img.endianness = 0;
	data->textures.west_img.ptr = NULL;
	data->textures.west_img.address = NULL;
	data->textures.west_img.bpp = 0;
	data->textures.west_img.line_length = 0;
	data->textures.west_img.endianness = 0;
}

void	ft_init_screen(t_data *data)
{
	t_img	screen_img;

	screen_img.ptr = NULL;
	screen_img.address = NULL;
	screen_img.bpp = 0;
	screen_img.line_length = 0;
	screen_img.endianness = 0;
	data->screen = screen_img;
}

/*
@MARK
INIT LIST DATA 
This functions is use to initialize the head of
any linked list store in the struct data
*/
void	ft_init_data(t_data *data)
{
	data->garbage_ctr = NULL;
	data->map = NULL;
	data->colors = NULL;
	data->direction = NULL;
	data->params = NULL;
	ft_init_textures(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error_free_exit(data, "Could not initialize mlx pointer\n");
	data->mlx_allocated = true;
	data->window_ptr = mlx_new_window(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if ((data->window_ptr) == NULL)
		ft_error_free_exit(data, "Could not create the window\n");
	data->window_allocated = true;
	data->keys_pressed.w_pressed = false;
	data->keys_pressed.a_pressed = false;
	data->keys_pressed.s_pressed = false;
	data->keys_pressed.d_pressed = false;
	ft_init_screen(data);
}
