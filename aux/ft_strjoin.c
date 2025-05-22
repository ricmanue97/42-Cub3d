/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:17:28 by dicarval          #+#    #+#             */
/*   Updated: 2025/03/31 16:42:06 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*nwstr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (s1);
	nwstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (nwstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nwstr[i + j] = s2[j];
		j++;
	}
	nwstr[i + j] = '\0';
	return (nwstr);
}
