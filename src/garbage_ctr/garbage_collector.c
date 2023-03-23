/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:45:02 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/03 12:52:19 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

void *ft_malloc(t_data *data, int len)
{
    void *node;

    node = malloc(len);
    if (!node)
        return (NULL);
    if(add_addr_to_garbage(&data, node) != SUCCESS)
        error_handler(data ,MALLOC_ERROR);
    return (node);
}

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
}