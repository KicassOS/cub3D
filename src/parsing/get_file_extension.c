/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:22:17 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/01 03:44:58 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"
/*
  This function checks if the filename is valid, meaning it has at least
  one character before the . and the extension is .cub
  For example: a.cub is valid, but .cub and lol.cublele are not
*/
bool	ft_valid_extension(char *filename)
{
	int	len;

	if (filename == NULL)
		return (false);
	len = ft_strlen(filename);
	if (len > 4 && filename[len - 4] == '.' && filename[len - 3] == 'c' \
		&& filename[len - 2] == 'u' && filename[len - 1] == 'b' \
		&& filename[len] == '\0')
		return (true);
	return (false);
}
