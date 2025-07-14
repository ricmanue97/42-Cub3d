/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:18 by ricmanue          #+#    #+#             */
/*   Updated: 2025/07/14 11:04:37 by ricmanue         ###   ########.fr       */
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

static int	ft_is_valid_number(const char *str)
{
	int	j;
	int	flag;

	j = 0;
	while (str[j] == ' ' && str[j])
		j++;
	if (str[j] == '\0')
		return (UNSUCCESS);
	flag = 0;
	j = -1;
	while (str[++j])
	{
		if (str[j] == ' ')
			continue ;
		else if (str[j] < '0' || str[j] > '9')
			return (UNSUCCESS);
		else if (str[j] >= '0' && str[j] <= '9' && flag == 1)
			return (UNSUCCESS);
		else if (str[j] >= '0' && str[j] <= '9' && str[j + 1] == ' ')
			flag = 1;
	}
	return (SUCCESS);
}

int	ft_check_number(char **conversion)
{
	int	i;

	i = 0;
	while (conversion[i])
	{
		if (ft_is_valid_number(conversion[i]) != SUCCESS)
			return (UNSUCCESS);
		i++;
	}
	return (SUCCESS);
}

int	ft_check_rgbnum(char **conversion, char flag, int *code)
{
	int	j;

	j = 0;
	if (ft_check_number(conversion) != SUCCESS)
		return (free_double_p((void **)conversion), UNSUCCESS);
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
	else
		return (free_double_p((void **)conversion), UNSUCCESS);
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
		return (ft_putstr_fd("Error : invalid color", 2, YES), UNSUCCESS);
	conversion = ft_split(&color[i], ',');
	if (ft_check_rgbnum(conversion, flag, code) != SUCCESS)
		return (ft_putstr_fd("Error : invalid color", 2, YES), UNSUCCESS);
	if (conversion)
	{
		j = 0;
		while (conversion[j])
			free(conversion[j++]);
		free(conversion);
	}
	return (SUCCESS);
}
