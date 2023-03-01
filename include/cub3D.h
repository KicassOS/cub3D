/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:06:03 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/01 13:50:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define Q_KEY 113
# define ESC_KEY 65307

# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

typedef struct s_data {
	void	*mlx_ptr;
	void	*window_ptr;
	bool	window_allocated;
	bool	mlx_allocated;
	double	playerPosX;
	double	playerPosY;
	double	playerDirX;
	double	playerDirY;
	double	cameraPlaneX;
	double	cameraPlaneY;
	double	time;
	double	oldTime;
} t_data;

#endif
