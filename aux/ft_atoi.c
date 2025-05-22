/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:47:53 by ricmanue          #+#    #+#             */
/*   Updated: 2025/03/27 10:18:24 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	len;
	int	neg;
	int	nb;

	len = 0;
	neg = 1;
	nb = 0;
	while (str[len] == 12 || str[len] == 10 || str[len] == 13
		|| str[len] == 9 || str[len] == 11 || str[len] == 32)
		len++;
	if (str[len] == 43)
		len++;
	else if (str[len] == 45)
	{
		neg *= -1;
		len++;
	}
	while (ft_isdigit(str[len]))
	{
		nb = (nb * 10) + (str[len] - 48);
		len++;
	}
	nb = nb * neg;
	return (nb);
}
