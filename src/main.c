/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:34:29 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 18:17:50 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

int	cub_game(t_data *data, int ac, char **av)
{
	if (ac != 2)
		return (printf("Wrong number of arguments, \
				cub3D only takes one paramaters\n"), \
				FAILURE);
	init_lst_data(data);
	if (get_file(data, av[1]) != SUCCESS)
		error_handler(data, FAILURE);
	get_map(data);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	cub_game(&data, ac, av);
	ft_free(&data);
	return (0);
}
