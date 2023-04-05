/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:08:27 by gkitoko           #+#    #+#             */
/*   Updated: 2023/04/05 13:23:04 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
/*
 *      check "is" function
 *
*/
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isprint(int c);
/*
 *	str manipulation functiom
 *
*/
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(t_data *data, char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(t_data *data, char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*
 * convert function
*/
int		ft_atoi(const char *str);
int		ft_toupper(int c);
char	*ft_itoa(int n);
int		ft_tolower(int c);
/*
 *	with malloc function
*/
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(t_data *data, const char *s);

#endif
