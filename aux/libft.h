/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:01:58 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/23 14:37:46 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line.h"

/* ************************************************************************** */
/*                                  CHECK                                     */
/* ************************************************************************** */

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprintable(int c);

/* ************************************************************************** */
/*                                  PRINT                                     */
/* ************************************************************************** */

void		ft_putstr_fd(char *s, int fd, int new_line);

/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

int			ft_countstr(char **strs);
size_t		ft_find_char(const char *str, char c);
char		*ft_itoa(int n);
char		**ft_split(char const *str, char spltr);
char		**ft_split2(char const *str, char spltr1, char spltr2);
char		*ft_strchr(char const *str, int c);
int			ft_strcmp(char const *c, char const *d);
char		*ft_strrchr(char const *str, int c);
char		*ft_strdup(char const *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin_var(unsigned int arg_n, ...);
size_t		ft_strlcpy(char *dest, char const *src, size_t n);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(char const *str);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_wordlen(const char *str, int start);
int			ft_atoi(const char *str);
int			ft_atoll(const char *str);

#endif
