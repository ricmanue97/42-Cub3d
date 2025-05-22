/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:54:29 by dicarval          #+#    #+#             */
/*   Updated: 2025/01/10 17:27:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_find_char(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len);
}
