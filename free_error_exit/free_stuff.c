
#include "../includes/cub.h"

void	free_string(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

void	free_double_p(void **pointer)
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
