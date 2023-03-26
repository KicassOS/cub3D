/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:38:39 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/26 17:35:26 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

/*
@MARK
INIT LIST DATA 
This functions is use to initialize the head of
any linked list store in the struct data
*/
void	init_lst_data(t_data *data)
{
	data->garbage_ctr = NULL;
	data->map = NULL;
	data->colors = NULL;
	data->direction = NULL;
	data->params = NULL;
}
