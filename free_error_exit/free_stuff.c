

#include "../includes/cube.h"

void	free_string(char *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

void	free_double_p(char **pointer)
{
	int	i;

	if (pointer)
	{
		i = -1;
		if (pointer[0])
		{
			while (pointer[++i])
				free_string(pointer[i]);
		}
		free(pointer);
		pointer = NULL;
	}
}
