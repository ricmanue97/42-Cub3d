/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:28:58 by dicarval          #+#    #+#             */
/*   Updated: 2025/03/13 11:40:28 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *c, char const *d)
{
	int	i;

	i = 0;
	if (!c || !d)
		return (-1);
	while (c[i] == d[i] && d[i])
		i++;
	if (d[i] == c[i])
		return (0);
	return (1);
}
