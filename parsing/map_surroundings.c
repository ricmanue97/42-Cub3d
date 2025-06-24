/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surroundings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:26 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/24 10:33:28 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_fill_map(char **map)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len < cub()->map->m_width)
		{
			tmp = malloc(sizeof(char) * (cub()->map->m_width + 1));
			if (!tmp)
				return ;
			ft_strcpy(tmp, map[i]);
			while (len < cub()->map->m_width)
			{
				tmp[len] = 'X';
				len++;
			}
			tmp[len] = '\0';
			free(map[i]);
			map[i] = tmp;
		}
		i++;
	}
}

int	ft_check_surround(char **map, int i, int j)
{
	if (i == 0 && (map[i][j] != 'X' && map[i][j] != '1'))
		return (UNSUCCESS);
	else if (i == cub()->map->m_height - 1 && (map[i][j] != 'X' \
	&& map[i][j] != '1'))
		return (UNSUCCESS);
	else if (j == 0 && (map[i][j] != 'X' && map[i][j] != '1'))
		return (UNSUCCESS);
	else if (j == cub()->map->m_width - 1 && (map[i][j] != 'X' \
	&& map[i][j] != '1'))
		return (UNSUCCESS);
	else if (j > 0 && i > 0)
	{
		if (j + 1 < cub()->map->m_width && map[i][j + 1] == 'X')
			return (UNSUCCESS);
		if (j - 1 > 0 && map[i][j - 1] == 'X')
			return (UNSUCCESS);
		if (i + 1 < cub()->map->m_height && map[i + 1][j] == 'X')
			return (UNSUCCESS);
		if (i - 1 > 0 && map[i - 1][j] == 'X')
			return (UNSUCCESS);
	}
	return (SUCCESS);
}

int	ft_validate_map_surroundings(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && ft_check_surround(map, i, j) != SUCCESS)
			{
				ft_putstr_fd("Error : invalid map", 2, YES);
				return (UNSUCCESS);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_validate_map_player(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'W' || map[i][j] == 'N' || \
			map[i][j] == 'E' || map[i][j] == 'S'))
			{
				if (cub()->player->dir != 'A')
					return (UNSUCCESS);
				if (ft_check_surround(map, i, j) != SUCCESS)
					return (UNSUCCESS);
				cub()->player->dir = map[i][j];
				map[i][j] = '0';
				cub()->player->pos_x = j + 0.5;
				cub()->player->pos_y = i + 0.5;
			}
			j++;
		}
	}
	return (SUCCESS);
}

int	ft_validate_map(char **map)
{
	if (!map[0])
	{
		ft_putstr_fd("Error : No map", STDERROR, YES);
		return (UNSUCCESS);
	}
	if (ft_validate_map_surroundings(map) != SUCCESS)
		return (UNSUCCESS);
	if (ft_validate_map_player(map) != SUCCESS)
		return (UNSUCCESS);
	if (cub()->player->dir == 'A')
	{
		ft_putstr_fd("Error : No player", STDERROR, YES);
		return (UNSUCCESS);
	}
	return (SUCCESS);
}
