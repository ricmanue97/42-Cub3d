
#include "../includes/cube.h"

char	*ft_name_check(char *file)
{
	size_t	len;
	char	*file_path;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp((&file[len - 4]), ".cub", 4) != SUCCESS)
	{
		ft_putstr_fd("Error : not cub file\n", STDERROR, YES);
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
	while (line)
	{
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

void	ft_check_elements(char **elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[i][j])
	{
		j = 0;
		while (elements[i][j] && elements[i][j] == ' ')
			j++;
		if (elements[i][j] && (elements[i][j] == 'W' || elements[i][j] == 'E' || \
		elements[i][j] == 'S' || elements[i][j] == 'N' || elements[i][j] == 'F' || \
		elements[i][j] == 'C'))
		{
			ft_store_path();
			ft_validate_path();
		}
	}
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
	printf("%s", elements);
	split_elements = ft_split(elements, '\n');
	ft_check_elements(split_elements);
	close(fd);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./file_validation <mapfile.cub>\n", STDERROR, YES);
		return (1);
	}
	if (ft_args_validation(av) == 1)
		printf("SUCCESS");
	else
		printf("UNSUCCESS");
	return (0);
}

/*
Overview of the Parsing Process

    Entry Point — parser Function
        The parser function is the main entry point for parsing. It takes command-line arguments (argc, argv) and a pointer to a t_cub structure.
        It validates that exactly two arguments are passed (the program name and the map file name).
        The map file name is validated to ensure it ends with .cub using map_name_validator.

    File Handling and Early Error Checking
        The map file is opened for reading. If the file cannot be opened, an error is reported and parsing stops.

    Parsing Map Elements
        get_map_elements is called to read and extract elements from the map file (such as textures, colors, etc.).
        elements_validator checks if all required map elements are present and valid.

    Parsing Color Values
        get_rgb is called to parse RGB color values for the map. If there are invalid color values, an error is reported.

    Parsing the Map Layout
        get_cub_map reads the actual map layout from the file and populates the map data structure.
        If the map layout isn’t found, an error is triggered.

    Map Creation and Validation
        create_map processes the raw map data and creates an internal representation.
        cub_map_validator checks the validity of the final map (e.g., walls are closed, player position is valid, etc.).

Supporting Functions

    map_name_validator: Ensures the map file has a valid .cub extension and isn’t a directory.
    print_map: Displays parsed elements and the map for debugging purposes.

Key Data Structure

    The structure t_cub holds all data related to the map, elements, colors, and player position.

In summary:

The Cub3D parser validates the command-line input, checks the map file extension, opens and reads the file, parses the required elements (textures, colors), extracts the map layout, and performs a series of validations to ensure the map is ready for the game.

If you want a breakdown of any of the called helper functions (like get_map_elements, get_cub_map, etc.), let me know! */