/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:18:45 by ricmanue          #+#    #+#             */
/*   Updated: 2025/03/27 10:18:45 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numcount(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = numcount(n);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = 48;
	else if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		len--;
		if (n < 0)
			ptr[len] = (-(n % 10)) + 48;
		else
			ptr[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}
