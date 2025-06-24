/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:43 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/24 11:03:31 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*ft_name_check(char *file, int flag)
{
	size_t	len;
	char	*file_path;

	len = ft_strlen(file);
	if (flag == CUB)
	{
		if (len <= 4 || ft_strncmp((&file[len - 4]), ".cub", 4) != SUCCESS || \
		(ft_strncmp((&file[len - 5]), "/.cub", 5) == SUCCESS))
		{
			ft_putstr_fd("Error : not cub file", STDERROR, YES);
		}
	}
	else if (flag == XPM)
	{
		if (len <= 4 || ft_strncmp((&file[len - 4]), ".xpm", 4) != SUCCESS || \
		(ft_strncmp((&file[len - 5]), "/.xpm", 5) == SUCCESS))
			return (NULL);
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

int	ft_args_validation(char **av)
{
	int		fd;
	char	*elements;
	char	**split_elm;

	fd = open(ft_name_check(av[1], CUB), O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : opening file", STDERROR, YES);
		return (UNSUCCESS);
	}
	close(fd);
	elements = ft_get_elements(av);
	if (!elements)
	{
		ft_putstr_fd("Error : wrong amount of elements", STDERROR, YES);
		return (free_pointer(elements), UNSUCCESS);
	}
	split_elm = ft_split(elements, '\n');
	if (ft_check_elements(split_elm) != SUCCESS)
	{
		free(elements);
		free_double_p((void **)split_elm);
		return (UNSUCCESS);
	}
	return (free_double_p((void **)split_elm), free_pointer(elements), SUCCESS);
}
