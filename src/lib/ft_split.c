/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:35:59 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/01 03:44:05 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define.h"

static int	ft_ischarset(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_countwords(char const *str, char sep)
{
	int	wc;
	int	i;

	i = 0;
	wc = 0;
	while (str[i] && ft_ischarset(str[i], sep))
		i++;
	while (str[i])
	{
		wc++;
		while (str[i] && !ft_ischarset(str[i], sep))
			i++;
		while (str[i] && ft_ischarset(str[i], sep))
			i++;
	}
	return (wc);
}

static char	*ft_dup(t_data *data, char const *str, char sep)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	i = 0;
	while (str[len] && !ft_ischarset(str[len], sep))
		len++;
	cpy = (char *)ft_malloc(data, sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && !ft_ischarset(str[i], sep))
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(t_data *data, char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = (char **)ft_malloc(data, sizeof(char *) * (ft_countwords(s, c)
				+ 1));
	if (!split)
		return (NULL);
	while (s[i] && ft_ischarset(s[i], c))
		i++;
	while (s[i])
	{
		split[j] = ft_dup(data, &s[i], c);
		while (s[i] && !ft_ischarset(s[i], c))
			i++;
		while (s[i] && ft_ischarset(s[i], c))
			i++;
		j++;
	}
	split[j] = 0;
	return (split);
}
