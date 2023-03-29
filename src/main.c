/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:29 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/29 08:32:29 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

void	init_cub3D(t_data *data, int ac, char **av)
{
	ft_init_data(data);
	if (get_file(data, av[1]) != SUCCESS)
		error_handler(data, FAILURE);
	get_map(data);
}

int	ft_game_loop(t_data *data)
{
	ft_move_player(data);
	ft_render_frame(data);
	mlx_destroy_image(data->mlx_ptr, data->screen.ptr);
	data->screen.ptr = NULL;
	return (EXIT_SUCCESS);
}

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->window_ptr, KeyPress, KeyPressMask, \
	ft_handle_keypress, (void *) data);
	mlx_hook(data->window_ptr, KeyRelease, KeyReleaseMask, \
	ft_handle_keyrelease, (void *) data);
	mlx_hook(data->window_ptr, \
	DestroyNotify, ButtonPressMask, ft_free_exit, (void *) data);
	mlx_loop_hook(data->mlx_ptr, ft_game_loop, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("Error:\ncub3D expects one argument: the map to load\n");
		return (EXIT_FAILURE);
	}
	init_cub3D(&data, ac, av);
	ft_init_hooks(&data);
	mlx_loop(data.mlx_ptr);
	ft_free(&data);
	return (0);
}
