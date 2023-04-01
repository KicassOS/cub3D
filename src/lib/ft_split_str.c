/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:10:36 by pszleper          #+#    #+#             */
/*   Updated: 2023/04/01 08:16:28 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/define.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length_src;

	i = 0;
	length_src = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length_src);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static char	*ft_alloc_and_copy_str(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static void	ft_free_all_substrs(char **strings_ptr, size_t current_index)
{
	if (!strings_ptr)
		return ;
	if (current_index == 0)
	{
		free(strings_ptr);
		return ;
	}
	while (current_index > 0)
	{
		current_index--;
		free(strings_ptr[current_index]);
	}
	free(strings_ptr);
}

char	**ft_split_str(char const *s, char c)
{
	char		**strings;
	size_t		i;
	size_t		strings_length;

	if (!s)
		return (NULL);
	strings_length = ft_word_count(s, c);
	strings = malloc(sizeof(char *) * (strings_length + 1));
	if (!strings)
		return (NULL);
	i = -1;
	while (++i < strings_length)
	{
		while (*s == c)
			s++;
		strings[i] = ft_alloc_and_copy_str(s, c);
		if (!strings[i])
		{
			ft_free_all_substrs(strings, i);
			return (NULL);
		}
		s += ft_strlen(strings[i]);
	}
	strings[i] = NULL;
	return (strings);
}
