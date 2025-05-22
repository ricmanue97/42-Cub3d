/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:01:58 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/05 16:11:55 by dicarval         ###   ########.fr       */
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
# include "../include/minishell.h"

typedef struct s_env	t_env;
typedef struct s_input	t_input;

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

/* ************************************************************************** */
/*                                  STRUCT                                    */
/* ************************************************************************** */

void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*ft_lstlast_env(t_env *lst);
size_t		ft_lstsize_env(t_env *n);

int			ft_lstadd_back_cmd(t_input **lst, t_input *new);
t_input		*ft_lstnew_cmd(char *cmd_stx);
t_input		*ft_lstlast(t_input *lst);
size_t		ft_lstsize_input(t_input *n);

#endif
