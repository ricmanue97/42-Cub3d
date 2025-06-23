/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:48 by ricmanue          #+#    #+#             */
/*   Updated: 2025/06/23 15:45:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer_content [BUFFER_SIZE + 1];
	char		*actual_line;
	int			bytes;

	if ((fd < 0 && fd != 1) || BUFFER_SIZE <= 0)
		return (NULL);
	actual_line = NULL;
	while (ft_newline(actual_line) == -1)
	{
		if (buffer_content[0] == '\0')
		{
			bytes = read(fd, buffer_content, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes == 0)
					return (actual_line);
				free(actual_line);
				return (NULL);
			}
			buffer_content[bytes] = '\0';
		}
		actual_line = ft_strjoin_gnl(actual_line, buffer_content);
		ft_cleanread(actual_line, buffer_content);
	}
	return (actual_line);
}
/*
int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = 1;

	while ((line = get_next_line(fd)))
	{
		if (fd == 0 && line[0] == 'e' 	&& line[3] == 't')
		{
			free (line);
			return (0);
		}
		printf("%d->%s", lines++, line);
		free(line);
	}

} */
/* int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("file.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%d->%s", lines++, line);
		free(line);
	}
} */
