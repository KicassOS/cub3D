/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:08:30 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/04 21:26:43 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

t_node	*get_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
/*
@MARK
Those functions below are used to create/add node of their own data type.
You can use the same code structures to implement your
own linked list adding function.
*/

int	add_node_params(t_data **data, char *line)
{
	t_params	*tmp;

	tmp = NULL;
	if (!(*data)->params)
	{
		(*data)->params = (t_params *)lst_new_params(*data, line);
		if (!(*data)->params)
			return (MALLOC_ERROR);
		return (SUCCESS);
	}
	tmp = (*data)->params;
	tmp = (t_params *)get_last_node((t_node *)(tmp));
	tmp->next = (t_params *)lst_new_params(*data, line);
	if (!tmp->next)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

int	add_node_colors(t_data **data, char *name, char *rgb)
{
	t_colors	*tmp;

	tmp = NULL;
	if (!(*data)->colors)
	{
		(*data)->colors = (t_colors *)lst_new_rgb(*data, name, rgb);
		if (!(*data)->colors)
			return (MALLOC_ERROR);
		return (SUCCESS);
	}
	tmp = (*data)->colors;
	tmp = (t_colors *)get_last_node((t_node *)(tmp));
	tmp->next = (t_colors *)lst_new_rgb(*data, name, rgb);
	if (!tmp->next)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

int	add_direction_params(t_data **data, char *name, char *path)
{
	t_direction	*tmp;

	tmp = NULL;
	if (!(*data)->direction)
	{
		(*data)->direction = (t_direction *)lst_new_direction(*data, name,
				path);
		if (!(*data)->direction)
			return (MALLOC_ERROR);
		return (SUCCESS);
	}
	tmp = (*data)->direction;
	tmp = (t_direction *)get_last_node((t_node *)(tmp));
	tmp->next = (t_direction *)lst_new_direction(*data, name, path);
	if (!tmp->next)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

int	add_addr_to_garbage(t_data **data, void *ptr)
{
	t_garbage	*tmp;

	tmp = NULL;
	if (!(*data)->garbage_ctr)
	{
		(*data)->garbage_ctr = (t_garbage *)lst_new_garbage(*data, ptr);
		if (!(*data)->garbage_ctr)
		{
			return (MALLOC_ERROR);
		}
		return (SUCCESS);
	}
	tmp = (*data)->garbage_ctr;
	tmp = (t_garbage *)get_last_node((t_node *)(tmp));
	tmp->next = (t_garbage *)lst_new_garbage(*data, ptr);
	if (!tmp->next)
		return (MALLOC_ERROR);
	return (SUCCESS);
}
