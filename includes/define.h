/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:58:50 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/02 19:57:27 by pszleper         ###   ########.fr       */
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
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdint.h>
# include "mlx.h"

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

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 800

# define TEXTURE_SIZE 128

# define VERTICAL 0
# define HORIZONTAL 1

# define WALL  '1'
# define NORTH 'N'
# define EAST  'E'
# define SOUTH 'S'
# define WEST  'W'

# include "struct.h"
# include "function.h"
# include "libft.h"

#endif
