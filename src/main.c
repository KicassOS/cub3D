/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:29 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 21:03:20 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

void	ft_init_game(t_data *data, char **av)
{
	ft_init_data(data);
	if (get_file(data, av[1]) != SUCCESS)
		error_handler(data, FAILURE);
	get_map(data);
	ft_load_textures(data);
	ft_load_floor_ceiling(data);
	ft_load_player_position(data);
	ft_load_player_orientation(data);
	ft_init_player_view(data);
	// init the player camera rotation
	// log the player and map info for testing
}

int	ft_game_loop(t_data *data)
{
	ft_move_player(data);
	// ft_rotate_player(data);
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
	DestroyNotify, ButtonPressMask, ft_close_hook, (void *) data);
	mlx_loop_hook(data->mlx_ptr, ft_game_loop, data);
}

int	main(int ac, char **av)
{
	t_data	data;
printf("REMOVE -g flag from makefile after project is done, dont delete this until then\n");
	if (ac != 2)
	{
		ft_putstr_fd("Error:\ncub3D expects one argument: the map to load\n"\
		, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_init_game(&data, av);
	ft_init_hooks(&data);
	mlx_loop(data.mlx_ptr);
	ft_free(&data);
	return (0);
}
