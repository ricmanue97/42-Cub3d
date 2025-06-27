/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:25:47 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/27 11:36:04 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_line_start(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		return (UNSUCCESS);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (SUCCESS);
	else if (line[i] == ' ')
		return (SUCCESS);
	else if (line[i] == '0')
		return (SUCCESS);
	return (UNSUCCESS);
}

int	ft_map_size(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' \
			&& map[i][j] != 'W' && map[i][j] != 'N' && map[i][j] != 'E' \
			&& map[i][j] != 'S')
				return (UNSUCCESS);
			if (map[i][j] == ' ')
				map[i][j] = 'X';
		}
		if (cub()->map->m_width < j)
			cub()->map->m_width = j;
	}
	cub()->map->m_height = i;
	return (SUCCESS);
}

int	ft_store_map(char *map)
{
	int		i;
	char	**coord_map;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] && map[i + 1] == '\n' && map[i + 2] \
		&& (map[i + 2] == '1' || map[i + 2] == '1' || map[i + 2] == ' '))
		{
			ft_putstr_fd("Error : empty line in map", STDERROR, YES);
			return (free(map), UNSUCCESS);
		}
	}
	coord_map = ft_split(map, '\n');
	cub()->map->coord = coord_map;
	free_pointer(map);
	if (ft_map_size(cub()->map->coord) != SUCCESS)
	{
		ft_putstr_fd("Error : invalid character", 2, YES);
		return (UNSUCCESS);
	}
	ft_fill_map(cub()->map->coord);
	if (ft_validate_map(cub()->map->coord) != SUCCESS)
		return (UNSUCCESS);
	return (SUCCESS);
}

int	ft_read_and_append_lines(int fd, char **map)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_line_start(line) == SUCCESS)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		tmp = *map;
		*map = ft_strjoin(*map, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	if (!map)
		return (free(line), UNSUCCESS);
	free_pointer(line);
	return (SUCCESS);
}

int	ft_check_map(char **av)
{
	int		fd;
	char	*map;

	map = ft_strdup("");
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
	{
		ft_putstr_fd("Error : opening file", 2, YES);
		return (ERROR_START);
	}
	if (ft_read_and_append_lines(fd, &map) != SUCCESS)
	{
		free_pointer(map);
		close(fd);
		return (UNSUCCESS);
	}
	close(fd);
	return (ft_store_map(map));
}
