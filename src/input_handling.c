/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:11:34 by pszleper          #+#    #+#             */
/*   Updated: 2023/03/29 07:20:37 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

int	ft_handle_keypress(int key, t_data *data)
{
	if (key == ESC)
		ft_free_exit(data);
	if (key == W_KEY)
		data->keys_pressed.w_pressed = true;
	if (key == A_KEY)
		data->keys_pressed.a_pressed = true
	if (key == S_KEY)
		data->keys_pressed.s_pressed = true;
	if (key == D_KEY)
		data->keys_pressed.d_pressed = true;
	return (EXIT_SUCCESS);
}

int	ft_handle_keyrelease(int key, t_data *data)
{
	if (key == W_KEY)
		data->keys_pressed.w_pressed = false;
	if (key == A_KEY)
		data->keys_pressed.a_pressed = false;
	if (key == S_KEY)
		data->keys_pressed.s_pressed = false;
	if (key == D_KEY)
		data->keys_pressed.d_pressed = false;
	return (EXIT_SUCCESS);
}
