/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:12:17 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/01 04:16:40 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_extract_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->address + (y * img->line_length) \
	+ (x * img->bpp / 8)));
}

uint32_t	ft_get_side_pixel(t_data *data, t_raycaster *rayc)
{
	if (rayc->side == VERTICAL)
	{
		if (data->player.x > rayc->map_x)
			return (ft_extract_pixel(&data->textures.west_img,
					rayc->tex_x, rayc->tex_y));
		return (ft_extract_pixel(&data->textures.east_img,
				rayc->tex_x, rayc->tex_y));
	}
	else
	{
		if (data->player.y > rayc->map_y)
			return (ft_extract_pixel(&data->textures.north_img,
					rayc->tex_x, rayc->tex_y));
		return (ft_extract_pixel(&data->textures.south_img,
				rayc->tex_x, rayc->tex_y));
	}
}
