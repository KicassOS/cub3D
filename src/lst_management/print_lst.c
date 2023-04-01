/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:16:38 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 04:13:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

void	print_params_content(t_params *node)
{
	t_params	*tmp;

	if (node == NULL)
		return ;
	tmp = node;
	while (tmp)
	{
		printf("%s ->\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_direction_list(t_direction *node)
{
	t_direction	*tmp;

	if (node == NULL)
		return ;
	tmp = node;
	while (tmp)
	{
		printf("name : %s path : %s->\n ", tmp->name, tmp->path);
		tmp = tmp->next;
	}
}

void	print_colors_list(t_colors *node)
{
	t_colors	*tmp;

	if (node == NULL)
		return ;
	tmp = node;
	while (tmp)
	{
		printf("name : %s rgb : %s->\n ", tmp->name, tmp->rgb);
		tmp = tmp->next;
	}
}
