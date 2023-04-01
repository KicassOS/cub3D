/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:00:01 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 08:37:37 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_garbage
{
	struct s_garbage	*next;
	void				*addr;
}	t_garbage;

typedef struct s_colors
{
	struct s_colors		*next;
	char				*name;
	char				*rgb;
}	t_colors;

typedef struct s_direction
{
	struct s_direction	*next;
	char				*name;
	char				*path;
}	t_direction;

typedef struct s_params
{
	struct s_params		*next;
	char				*content;
}	t_params;

typedef struct s_require_params
{
	int					north;
	int					south;
	int					west;
	int					east;
	int					floor;
	int					cell;
}	t_require_params;

typedef struct s_img
{
	void	*ptr;
	char	*address;
	int		bpp;
	int		line_length;
	int		endianness;
}	t_img;

typedef struct s_textures
{
	int		sky_colors[3];
	int		floor_colors[3];
	t_img	north_img;
	t_img	east_img;
	t_img	south_img;
	t_img	west_img;
}	t_textures;

typedef struct s_player
{
	double	x;
	double	y;
	char	orientation;
	double	angle;
}	t_player;

typedef struct s_keys
{
	bool	w_pressed;
	bool	s_pressed;
	bool	a_pressed;
	bool	d_pressed;
	bool	larr_pressed;
	bool	rarr_pressed;
}	t_keys;

typedef struct s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct s_raycaster
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	distance;
	double	step;
	int		step_x;
	int		step_y;
	bool	hit;
	int		side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycaster;

typedef struct s_data
{
	t_garbage			*garbage_ctr;
	t_params			*params;
	unsigned int		last_params_line;
	t_require_params	params_required;
	t_colors			*colors;
	t_textures			textures;
	t_direction			*direction;
	unsigned int		map_size;
	char				**map;
	char				**file_arr;
	void				*mlx_ptr;
	bool				mlx_allocated;
	bool				window_allocated;
	void				*window_ptr;
	t_player			player;
	t_keys				keys_pressed;
	t_img				screen;
	t_camera			camera;
	int					tex_width;
	int					tex_height;
}	t_data;

typedef struct s_node
{
	struct s_node		*next;
}	t_node;

#endif