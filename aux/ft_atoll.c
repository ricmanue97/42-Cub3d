/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:43:14 by ricmanue          #+#    #+#             */
/*   Updated: 2025/07/14 08:30:18 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_atoll_helper(const char *str, int *err, int i)
{
	long long	res;
	int			digit;

	res = 0;
	*err = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (res > (LLONG_MAX - digit) / 10)
		{
			*err = 1;
			return (0);
		}
		res = res * 10 + digit;
		i++;
	}
	return (1);
}

int	ft_atoll(const char *str)
{
	int	err;
	int	i;
	int	flag;

	i = 0;
	flag = ft_atoll_helper(str, &err, i);
	if (err || !str[0] || (((str[0] == '-' || str[0] == '+')) \
&& !ft_isdigit(str[1])))
		return (flag);
	return (flag);
}
