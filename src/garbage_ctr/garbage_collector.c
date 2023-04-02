/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:45:02 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/02 17:33:13 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

/*
@MARK
This function is used instead using the standard function malloc,
	it takes a pointer type data
and the len of the datum you want to store.
*/
void	*ft_malloc(t_data *data, int len)
{
	void	*node;

	node = malloc(len);
	if (!node)
		return (NULL);
	if (add_addr_to_garbage(&data, node) != SUCCESS)
		error_handler(data, MALLOC_ERROR);
	return (node);
}

void	ft_free_images(t_data *data)
{
	if (data->textures.north_img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.north_img.ptr);
	if (data->textures.east_img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.east_img.ptr);
	if (data->textures.south_img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.south_img.ptr);
	if (data->textures.west_img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->textures.west_img.ptr);
}

/*
@MARK
This function is used only once at the end of the program and
 it frees every data stored from ft_malloc.
*/

void	ft_free(t_data *data)
{
	t_garbage	*lst;
	t_garbage	*tmp;

	lst = data->garbage_ctr;
	while (lst)
	{
		tmp = lst->next;
		free(lst->addr);
		lst->addr = NULL;
		free(lst);
		lst = tmp;
	}
	data->garbage_ctr = NULL;
	ft_free_images(data);
	if (data->window_allocated == true)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	if (data->mlx_allocated == true)
		free(data->mlx_ptr);
}

void	ft_free_exit(t_data *data)
{
	ft_free(data);
	exit(EXIT_SUCCESS);
}

void	ft_error_free_exit(t_data *data, char *err_msg)
{
	ft_free(data);
	if (err_msg != NULL)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
