/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:58:50 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 18:40:24 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
// # include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include "struct.h"
# include "function.h"
# include "../src/lib/libft.h"

# define FAILURE -1
# define MALLOC_ERROR -42
# define MAP_ERROR -342
# define PARAMS_ERROR -442
# define INVALID_FILE -242
# define INVALID_VALUE -21
# define SUCCESS 0
# define MLX_ERROR 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#endif
