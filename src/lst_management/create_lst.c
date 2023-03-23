/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:53:44 by gkitoko           #+#    #+#             */
/*   Updated: 2023/03/03 14:56:07 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

t_node *lst_new_params(t_data *data, char *line)
{
    t_params *node;

    if (!line)
        return (NULL);
    node = ft_malloc(data, sizeof(t_params));
    if (!node)
        return (NULL);  
    node->next = NULL;
    node->content = ft_strdup(data, line);
    return ((t_node *)node);
}

t_node *lst_new_direction(t_data *data, char *name, char *path)
{
    t_direction *node;

    if (!name || !path)
        return (NULL);
    node = ft_malloc(data, sizeof(t_direction));
    if (!node)
        return (NULL);  
    node->next = NULL;
    node->name = ft_strdup(data, name);
    node->path = ft_strdup(data, path);
    return ((t_node *)node);
}

t_node *lst_new_rgb(t_data *data, char *name, char *rgb)
{
    t_colors *node;

    if (!name || !rgb)
        return (NULL);
    node = ft_malloc(data, sizeof(t_colors));
    if (!node)
        return (NULL);  
    node->next = NULL;
    node->name = ft_strdup(data, name);
    node->rgb = ft_strdup(data, rgb);
    return ((t_node *)node);
}

t_node *lst_new_garbage(void *ptr)
{
    t_garbage *node;

    if (!ptr)
        return (NULL);
    node = malloc(sizeof(t_garbage));
    if (!node)
        return (NULL);
    node->next = NULL;
    node->addr = ptr;
    return ((t_node *)node); 
}
