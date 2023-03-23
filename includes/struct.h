/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:00:01 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/12 17:25:09 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum direction
{
    NO,
    SO,
    WE,
    EA
};

typedef struct s_garbage
{
    struct s_garbage *next;
    void *addr;
} t_garbage;

typedef struct s_colors
{
    struct s_colors *next;
    char *name;
    char *rgb;
} t_colors;

typedef struct s_direction
{
    struct s_direction *next;
    char *name;
    char *path;
} t_direction;

typedef struct s_params
{
    struct s_params *next;
    char *content;
} t_params;

typedef struct s_require_params
{
    int north;
    int south;
    int west;
    int east;
    int floor;
    int cell;
} t_require_params;

typedef struct s_data
{
    t_garbage       *garbage_ctr;
    t_params        *params;
    unsigned int    last_params_line;
    t_require_params params_required;
    t_colors        *colors;
    t_direction     *direction;
    unsigned int    map_size;
    char            **map;
    char            **file_arr;
} t_data;

typedef struct s_node
{
	struct s_node			*next;
}							t_node;

#endif