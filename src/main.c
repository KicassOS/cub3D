/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:28:51 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/01 19:37:02 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_data(t_data *data)
{
	if (data->window_allocated == true)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	if (data->mlx_allocated == true)
		free(data->mlx_ptr);
}

void	ft_close(t_data *data)
{
	ft_free_data(data);
	exit(EXIT_SUCCESS);
}

int	ft_handle_input(int key, void *data)
{
	if (key == W_KEY)
		return (0);
	else if (key == A_KEY)
		return (0);
	else if (key == S_KEY)
		return (0);
	else if (key == D_KEY)
		return (0);
	else if (key == LEFT_ARROW)
		return (0);
	else if (key == RIGHT_ARROW)
		return (0);
	else if (key == ESC_KEY)
		ft_close(data);
	return (0);
}

void	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void	ft_print_error_exit(t_data *data, char *error_message, char exit_code)
{
	ft_putstr_fd(STDERR_FILENO, error_message);
	ft_free_data(data);
	exit(exit_code);
}

void	ft_init_data(t_data *data)
{
	data->playerPosX = 22;
	data->playerPosY = 12;
	data->playerDirX = -1;
	data->playerDirY = 0;
	data->cameraPlaneX = 0;
	data->cameraPlaneY = 0.66;
	data->time = 0;
	data->oldTime = 0;
	data->window_allocated = false;
	data->mlx_allocated = false;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_print_error_exit(data, "Could not initialize mlx\n", 2);
	data->mlx_allocated = true;
	data->window_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3D");
	if ((data->window_ptr) == NULL)
		ft_print_error_exit(data, "Could not create the window\n", 3);
	data->window_allocated = true;
}

int	ft_close_window_hook(t_data *data)
{
	ft_free_data(data);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	(void) argv;
	t_data	data;

	if (argc != 2)
		ft_print_error_exit(&data, "cub3D expects one argument\n", 1);
	ft_init_data(&data);
	mlx_hook(data.window_ptr, KeyPress, KeyPressMask, \
	ft_handle_input, (void *) &data);
	mlx_hook(data.window_ptr, \
	DestroyNotify, ButtonPressMask, ft_close_window_hook, (void *) &data);
/*	mlx_hook(data.window_ptr, Expose, ExposureMask, \
	ft_render, (void *) data);*/
	mlx_loop(data.mlx_ptr);
	ft_free_data(&data);
	return (EXIT_SUCCESS);
}
