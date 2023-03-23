/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:21:24 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/09 19:53:44 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FUNCTION_H
#define FUNCTION_H

// GET_NEXT_VALID
char	*ft_strjoin_line(char *s1, char *s2);
char	*get_next_line(int fd);
void	free_str(char *str);
// LST MANAGEMENT
void init_lst_data(t_data *data);
t_node *get_last_node(t_node *node);
int	add_node_params(t_data **data, char *line);
int	add_node_colors(t_data **data, char *name, char *rgb);
int add_direction_params(t_data **data, char *name, char *path);
t_node *lst_new_params(t_data *data, char *line);
t_node *lst_new_direction(t_data *data, char *name, char *path);
t_node *lst_new_rgb(t_data *data, char *name, char *rgb);
t_node *lst_new_garbage(void *ptr);
void	print_params_content(t_params *node);
void	print_direction_list(t_direction *node);
void	print_colors_list(t_colors *node);
// PARSING
int fill_params(t_data *data);
int check_empty_line(char *line);
int check_first_map_line(t_data *data, char *line);
int is_param_path(char *path);
int is_not_params(t_data *data, char *line);
int is_param_rgb(t_data *data, char *path);
void get_map(t_data *data);
int parse_node_params(t_data *data);
int is_digit_str(char *str);
int array_size(char **array);
void update_requirement_params(t_data *data, char *name);
void set_requirement(t_data *data);
int requirement_params_checker(t_data *data);
int is_valid_rgb(char **rgb);
int check_coma(char *rgb);
char *concact_rgb_w_space(t_data *data, char **array);
int fill_parsed_params(t_data *data);
int is_surrounded_by_space(t_data *data);
int is_one(char c);
int is_position(char c);
int is_floor(char c);
int check_only_one(t_data *data, char *line);
int check_wall(t_data *data, char *line);
int get_file(t_data *data, char *file);
//GARBAGE COLLECTOR
void	ft_free(t_data *data);
void *ft_malloc(t_data *data, int len);
int	add_addr_to_garbage(t_data **data, void *ptr);
// ERROR HANDLER
int error_handler(t_data *data, int error);

#endif