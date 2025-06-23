/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:12 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/23 11:34:45 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static char	*ft_read_elements(int fd, int num_elements)
{
	char	*line;
	char	*elements;
	char	*temp;

	elements = ft_strdup("");
	line = get_next_line(fd);
	while (line && num_elements < 6)
	{
		if (ft_check_line(line) == STOP)
			return (free(elements), free(line), NULL);
		if (ft_check_line(line) != SUCCESS)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		num_elements++;
		temp = ft_strjoin(elements, line);
		free(elements);
		elements = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (free_pointer((void *)line), elements);
}

char	*ft_get_elements(char **av)
{
	int		fd;
	int		num_elements;
	char	*elements;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : opening file", STDERROR, YES);
		exit(ERROR_START);
	}
	num_elements = 0;
	elements = ft_read_elements(fd, num_elements);
	close(fd);
	get_next_line(fd);
	return (elements);
}

int	ft_validate_path(int i, char *path)
{
	char	*file_path;

	while (path[i] && path[i] != ' ')
		i++;
	while (path[i] == ' ')
		i++;
	file_path = &path[i];
	i = 0;
	while (path[i] == ' ' && path[i])
		i++;
	if (path[i] == 'N' && (cub()->sprite_array[0].path == NULL))
		cub()->sprite_array[0].path = ft_strdup(file_path);
	else if (path[i] == 'E' && (cub()->sprite_array[1].path == NULL))
		cub()->sprite_array[1].path = ft_strdup(file_path);
	else if (path[i] == 'S' && (cub()->sprite_array[2].path == NULL))
		cub()->sprite_array[2].path = ft_strdup(file_path);
	else if (path[i] == 'W' && (cub()->sprite_array [3].path == NULL))
		cub()->sprite_array[3].path = ft_strdup(file_path);
	else
		return (UNSUCCESS);
	return (SUCCESS);
}

int	ft_store_path(char *path)
{
	int	i;

	i = 0;
	while (path[i] == ' ' && path[i])
		i++;
	if (ft_strncmp(&path[i], "NO ", 3) == SUCCESS)
		return (ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "SO ", 3) == SUCCESS)
		return (ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "WE ", 3) == SUCCESS)
		return (ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "EA ", 3) == SUCCESS)
		return (ft_validate_path(i, path));
	else if (path[i] == 'F' && !cub()->map->F)
		return (ft_check_rgbcode(&path[i], 'F'));
	else if (path[i] == 'C' && !cub()->map->C)
		return (ft_check_rgbcode(&path[i], 'C'));
	else
		return (UNSUCCESS);
	return (SUCCESS);
}

int	ft_check_elements(char **elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[i])
	{
		j = 0;
		while (elements[i][j] && elements[i][j] == ' ')
			j++;
		if (elements[i][j] && (elements[i][j] == 'W' || elements[i][j] == 'E' \
		|| elements[i][j] == 'S' || elements[i][j] == 'N' || \
		elements[i][j] == 'F' || elements[i][j] == 'C'))
		{
			if (ft_store_path(elements[i]) != SUCCESS)
			{
				ft_putstr_fd("Error : wrong path or invalid path", 2, YES);
				return (UNSUCCESS);
			}
		}
		i++;
	}
	return (SUCCESS);
}
