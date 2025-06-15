
#include "../includes/cub.h"

char	*ft_name_check(char *file)
{
	size_t	len;
	char	*file_path;

	len = ft_strlen(file);
	if (len <= 4 || ft_strncmp((&file[len - 4]), ".cub", 4) != SUCCESS || \
	(ft_strncmp((&file[len - 5]), "/.cub", 5) == SUCCESS))
	{
		ft_putstr_fd("Error : not cub file", STDERROR, YES);
		exit(FILENAME_ERROR);
	}
	file_path = file;
	return (file_path);
}

int	ft_check_line(char *line)
{
	int	i;

	if (!line)
		return (UNSUCCESS);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' \
	|| line[i] == 'F' || line[i] == 'C')
		return (SUCCESS);
	if (line[i] == '1' || line[i] == '0')
		return (STOP);
	return (UNSUCCESS);
}

char	*ft_get_elements(char **av)
{
	int		fd;
	int		num_elements;
	char	*line;
	char	*elements;
	char	*temp;

	elements = ft_strdup("");
	num_elements = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : opening file", STDERROR, YES);
		exit(ERROR_START);
	}
	line = get_next_line(fd);
	while (line && num_elements < 6)
	{
		if (ft_check_line(line) == STOP)
		{
			free(elements);
			free(line);
			close(fd);
			return(NULL);
		}
		if (ft_check_line(line) != SUCCESS)
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		num_elements++;
		temp = ft_strjoin(elements, line);
		free(elements);
		elements = temp;
		free(line);
		line = get_next_line(fd);
	}
	if (num_elements != 6)
	{
		free(elements);
		free(line);
		return(NULL);
	}
	free(line);
	close(fd);
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

void	ft_convert_hexadecimal(int *code, char c)
{
	unsigned long	hex_color;

	hex_color = ((unsigned long)code[0] << 16) | ((unsigned long)code[1] << 8) | code[2];
	if (c == 'F')
		cub()->map->F = hex_color;
	else if (c == 'C')
		cub()->map->C = hex_color;
}

int	ft_check_rgbcode(char *color, char flag)
{
	int	i;
	int		code[3];
	char	**conversion;

	i = 0;
	while (color[i] && (color[i] == 'F' || color[i] == 'C' || color[i] == ' '))
		i++;
	conversion = ft_split(&color[i], ',');
	if (conversion[0] && conversion[1] && conversion[2] && !conversion[3])
	{
		code[0] = ft_atoi(conversion[0]);
		code[1] = ft_atoi(conversion[1]);
		code[2] = ft_atoi(conversion[2]);
		if ((code[0] < 0 || code[0] > 255) || (code[1] < 0 || code[1] > 255) \
		|| (code[2] < 0 || code[2] > 255))
		{
			int j = 0;
			while (conversion[j])
				free(conversion[j++]);
			free(conversion);
			return (UNSUCCESS);
		}
		else
			ft_convert_hexadecimal(code, flag);
	}
	if (conversion)
	{
		int j = 0;
		while (conversion[j])
			free(conversion[j++]);
		free(conversion);
	}
	return (SUCCESS);
}

int	ft_store_path(char *path)
{
	int	i;

	i = 0;
	while (path[i] == ' ' && path[i])
		i++;
	if (ft_strncmp(&path[i], "NO ./", 5) == SUCCESS)
		return(ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "SO ./", 5) == SUCCESS)
		return(ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "WE ./", 5) == SUCCESS)
		return(ft_validate_path(i, path));
	else if (ft_strncmp(&path[i], "EA ./", 5) == SUCCESS)
		return(ft_validate_path(i, path));
	else if (path[i] == 'F')
		return (ft_check_rgbcode(&path[i], 'F'));
	else if (path[i] == 'C')
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
		if (elements[i][j] && (elements[i][j] == 'W' || elements[i][j] == 'E' || \
		elements[i][j] == 'S' || elements[i][j] == 'N' || elements[i][j] == 'F' || \
		elements[i][j] == 'C'))
		{
			if (ft_store_path(elements[i]) != SUCCESS)
			{
				ft_putstr_fd("Error : wrong or invalid path", 2, YES);
				return (UNSUCCESS);
			}
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_args_validation(char **av)
{
	int		fd;
	char	*elements;
	char	**split_elements;

	fd = open(ft_name_check(av[1]),O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : opening file", STDERROR, YES);
		exit(ERROR_START);
	}
	elements = ft_get_elements(av);
	if (!elements)
	{
		ft_putstr_fd("Error : wrong amount of elements", STDERROR, YES);
		exit(ERROR_START);
	}
	split_elements = ft_split(elements, '\n');
	if (ft_check_elements(split_elements) != SUCCESS)
		{
			free(elements);
			free_double_p((void **)split_elements);
			close(fd);
			free_cub(cub());
			return (UNSUCCESS);
		}
	close(fd);
	return (SUCCESS);
}
