
#include "../includes/cube.h"

char	*ft_name_check(char *file)
{
	size_t	len;
	char	*file_path;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp((&file[len - 4]), ".cub", 4) != SUCCESS)
	{
		ft_putstr_fd("Error : not ber file\n", STDERROR, YES);
		exit(FILENAME_ERROR);
	}
	file_path = file;
	return (file_path);
}

void	ft_get_textures(char **av)
{
	int	i;

	
}

int	ft_args_validation(char **av)
{
	int	fd;

	fd = open(ft_name_check(av[1]),O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : opening file", STDERROR, YES);
		exit(ERROR_START);
	}
	ft_get_textures(av);
	close(fd);
}
