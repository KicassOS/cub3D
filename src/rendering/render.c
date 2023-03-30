/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:49:14 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/30 21:09:00 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

t_img	ft_new_screen(void *mlx_ptr)
{
	t_img	new_screen;

	new_screen.ptr = mlx_new_image(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	new_screen.addr = mlx_get_data_addr(new_screen.ptr, &new_screen.bpp,
			&new_screen.line_len, &new_screen.endianness);
	return (new_screen);
}

static void	ft_draw_vertical_strip(t_data *data, t_raycaster *rayc, int x)
{
	int	y;

	y = -1;
	while (++y < rayc->draw_start)
	{
		ft_pixel_put(&data->canvas, x, y,
			create_trgb(256, data->textures.sky_colors[0],
				data->textures.sky_colors[1], data->textures.sky_colors[2]));
	}
	y = rayc->draw_start;
	while (y < rayc->draw_end)
	{
		rayc->tex_y = (int)rayc->tex_pos & (TEXTURE_HEIGHT - 1);
		rayc->tex_pos += rayc->step;
		ft_pixel_put(&data->canvas, x, y, ft_get_side_pixel(data, rayc));
		y += 1;
	}
	y = rayc->draw_end;
	while (y < SCREEN_HEIGHT)
	{
		ft_pixel_put(&data->canvas, x, y,
			create_trgb(256, data->textures.floor_colors[0], \
			data->textures.floor_colors[1], data->textures.floor_colors[2]));
		y += 1;
	}
}

void	ft_render_frame(t_data *data)
{
	int			x;
	t_raycaster	rayc;

	data->canvas = ft_new_screen(data->mlx_ptr);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ft_init_raycaster(data, &rayc, x);
		ft_init_rays(data, &rayc);
		ft_distance_to_wall(data->map, &rayc);
		ft_get_wall_height(&rayc);
		ft_get_wall_pixel(data, &rayc);
		ft_draw_vertical_strip(data, &rayc, x);
		x += 1;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->canvas.ptr, 0, 0);
}
