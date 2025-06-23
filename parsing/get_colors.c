/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:18 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/23 15:37:15 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_convert_hexadecimal(int *code, char c)
{
	unsigned long	hex_color;

	hex_color = ((unsigned long)code[0] << 16) | \
	((unsigned long)code[1] << 8) | code[2];
	if (c == 'F')
		cub()->map->f = hex_color;
	else if (c == 'C')
		cub()->map->c = hex_color;
}

int	ft_check_rgbnum(char **conversion, char flag, int *code)
{
	int	j;

	j = 0;
	if (conversion[0] && conversion[1] && conversion[2] && !conversion[3])
	{
		code[0] = ft_atoi(conversion[0]);
		code[1] = ft_atoi(conversion[1]);
		code[2] = ft_atoi(conversion[2]);
		if ((code[0] < 0 || code[0] > 255) || (code[1] < 0 || code[1] > 255) \
		|| (code[2] < 0 || code[2] > 255))
		{
			while (conversion[j])
				free(conversion[j++]);
			free(conversion);
			return (UNSUCCESS);
		}
		else
			ft_convert_hexadecimal(code, flag);
	}
	return (SUCCESS);
}

int	ft_check_rgbcode(char *color, char flag)
{
	int		i;
	int		j;
	int		code[3];
	char	**conversion;

	i = 0;
	while (color[i] && (color[i] == 'F' || color[i] == 'C' || color[i] == ' '))
		i++;
	if (color[i] < '0' || color[i] > '9')
		return (UNSUCCESS);
	conversion = ft_split(&color[i], ',');
	if (ft_check_rgbnum(conversion, flag, code) != SUCCESS)
		return (UNSUCCESS);
	if (conversion)
	{
		j = 0;
		while (conversion[j])
			free(conversion[j++]);
		free(conversion);
	}
	return (SUCCESS);
}
