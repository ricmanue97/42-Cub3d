// TODO: map delimeter changes to \0 from \n
// TODO: fill the spaces with "X"
// TODO: map is an array of characters
// TODO: X and Y starts in 1 not 0
// TODO: store player direction

#include "../includes/cube.h"

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

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' \
			&& map[i][j] != 'W' && map[i][j] != 'N' && map[i][j] != 'E' \
			&& map[i][j] != 'S')
				return (UNSUCCESS);
			if (map[i][j] == ' ')
				map[i][j] = 'X';
			else if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		if (cube()->map->map_width < j)
			cube()->map->map_width = j;
		i++;
	}
	cube()->map->map_height = i;
	return (SUCCESS);
}

void	ft_fill_map(char **map)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len < cube()->map->map_width)
		{
			tmp = malloc(sizeof(char) * (cube()->map->map_width + 1));
			if (!tmp)
				return ;
			ft_strcpy(tmp, map[i]);
			while (len < cube()->map->map_width)
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
	else if (i == cube()->map->map_height - 1 && (map[i][j] != 'X' && map[i][j] != '1'))
		return (UNSUCCESS);
	else if (j == 0 && (map[i][j] != 'X' && map[i][j] != '1'))
		return (UNSUCCESS);
	else if (j == cube()->map->map_width - 1 && (map[i][j] != 'X' && map[i][j] != '1'))
		return (UNSUCCESS);
	else
	{
		if ((map[i][j + 1] == 'X') || (map[i][j - 1] == 'X') \
		|| (map[i + 1][j] == 'X') || (map[i - 1][j] == 'X'))
			return (UNSUCCESS);
	}
	return (SUCCESS);
}

int	ft_validate_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_surround(map, i, j) != SUCCESS)
				return (UNSUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_store_map(char *map)
{
	int i = 0;
	cube()->map->coord = ft_split(map, '\n');
	if (ft_map_size(cube()->map->coord) != SUCCESS)
		return (UNSUCCESS);
	ft_fill_map(cube()->map->coord);
	while (cube()->map->coord[i])
	{
		printf("%s\n", cube()->map->coord[i]);
		i++;
	}
	if(ft_validate_map(cube()->map->coord) != SUCCESS)
	{
		printf("deu merda\n");
		return (UNSUCCESS);
	}
	return (SUCCESS);
}

int	ft_check_map(char **av)
{
	int		fd;
	char	*line;
	char	*map;

	map = ft_strdup("");
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
	{
		ft_putstr_fd("Error : opening file", 2, YES);
		return (ERROR_START);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_line_start(line) == SUCCESS)
			break ;
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	ft_store_map(map);
	return (SUCCESS);
}
