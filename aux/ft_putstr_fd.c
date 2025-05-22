/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:36 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/01 15:04:23 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int new_line)
{
	if (s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
	if (new_line == YES)
		write (fd, "\n", 1);
}
