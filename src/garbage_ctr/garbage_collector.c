/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:45:02 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 17:21:28 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

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
}
