/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:11:35 by dicarval          #+#    #+#             */
/*   Updated: 2025/01/21 09:13:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(const char *str, int start)
{
	size_t	len;

	len = 0;
	while (str[len + start] != '\0' && ft_isalnum(str[len + start]))
		len++;
	return (len);
}
