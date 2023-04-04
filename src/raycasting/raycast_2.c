/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:12:38 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/04 20:12:46 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

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
