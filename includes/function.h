/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:21:24 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/03 08:15:04 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

// GET_NEXT_VALID
char		*ft_strjoin_line(char *s1, char *s2);
char		*get_next_line(int fd);
void		free_str(char *str);
// LST MANAGEMENT
void		ft_init_data(t_data *data);
void ft_init_mxl(t_data *data);
t_node		*get_last_node(t_node *node);
int			add_node_params(t_data **data, char *line);
int			add_node_colors(t_data **data, char *name, char *rgb);
int			add_direction_params(t_data **data, char *name, char *path);
t_node		*lst_new_params(t_data *data, char *line);
t_node		*lst_new_direction(t_data *data, char *name, char *path);
t_node		*lst_new_rgb(t_data *data, char *name, char *rgb);
t_node		*lst_new_garbage(void *ptr);
void		print_params_content(t_params *node);
void		print_direction_list(t_direction *node);
void		print_colors_list(t_colors *node);
// PARSING
int			fill_params(t_data *data);
int			check_empty_line(char *line);
int			check_first_map_line(t_data *data, char *line);
int			is_param_path(char *path);
int			is_not_params(t_data *data, char *line);
int			is_param_rgb(t_data *data, char *path);
void		get_map(t_data *data);
int			set_map_size(t_data *data);
int			parse_node_params(t_data *data);
int			is_digit_str(char *str);
int			array_size(char **array);
void		update_requirement_params(t_data *data, char *name);
void		set_requirement(t_data *data);
int			requirement_params_checker(t_data *data);
int			is_valid_rgb(char **rgb);
int			check_coma(char *rgb);
char		*concact_rgb_w_space(t_data *data, char **array);
int			fill_parsed_params(t_data *data);
int			is_surrounded_by_space(t_data *data);
int			is_one(char c);
int			is_position(char c);
int			is_floor(char c);
int			check_only_one(t_data *data, char *line);
int			file_to_array(t_data *data, char *file_store);
int			check_wall(t_data *data, char *line);
bool		ft_valid_extension(char *filename);
int			valid_arg(char *arg);
int			check_only_one_not_parsed(t_data *data, char *line);
char		*get_right_line(t_data *data, char *file_line, char *tmp, \
			int *detect);
char		*cub_to_str(t_data *data, char *file);
int			iterate_map(t_data *data, char **map);
void		check_map_cell(t_data *data, char **map, unsigned int index, int j);
int			get_file(t_data *data, char *file);
int			is_valid_element(t_data *data, char c);
void		requirement_map_loop(t_data *data, char *map, unsigned int line, \
				int *counter);
int			check_is_space(t_data *data, char **map, unsigned int index, int j);
//GARBAGE COLLECTOR
void		free_and_null(void *var);
void		ft_free(t_data *data);
void		ft_free_exit(t_data *data);
void		ft_error_free_exit(t_data *data, char *error_message);
void		*ft_malloc(t_data *data, int len);
int			add_addr_to_garbage(t_data **data, void *ptr);
// ERROR HANDLER
void		malloc_error(t_data *data);
void		map_error(t_data *data);
void		params_error(t_data *data);
void		invalid_file(t_data *data);
void		invalid_value(t_data *data);
int			error_handler(t_data *data, int error);
// getters
char		*ft_get_north_path(t_data *data);
char		*ft_get_south_path(t_data *data);
char		*ft_get_west_path(t_data *data);
char		*ft_get_east_path(t_data *data);
char		*ft_get_floor_path(t_data *data);
char		*ft_get_ceil_path(t_data *data);
void		ft_load_player_orientation(t_data *data);
void		ft_init_player_view(t_data *data);
//info loading
void		ft_load_textures(t_data *data);
void		ft_load_player_position(t_data *data);
void		ft_load_player_orientation(t_data *data);
void		ft_load_floor_ceiling(t_data *data);
// input_handling
int			ft_handle_keypress(int key, t_data *data);
int			ft_handle_keyrelease(int key, t_data *data);
void		ft_move_player(t_data *data);
void		ft_rotate_player(t_data *data);
int			ft_close_hook(void *data);
// rendering
int			ft_create_trgb(int t, int r, int g, int b);
void		ft_pixel_put(t_img *img, int x, int y, unsigned int color);
int			ft_extract_pixel(t_img *img, int x, int y);
uint32_t	ft_get_side_pixel(t_data *data, t_raycaster *rayc);
void		ft_render_frame(t_data *data);
// raycasting
void		ft_init_raycaster(t_data *data, t_raycaster *rayc, int x);
void		ft_init_rays(t_data *data, t_raycaster *rayc);
void		ft_distance_to_wall(char **map, t_raycaster *rayc);
void		ft_get_wall_height(t_raycaster *rayc);
void		ft_get_wall_pixel(t_data *data, t_raycaster *rayc);

char	**ft_split_str(char const *s, char c);

#endif