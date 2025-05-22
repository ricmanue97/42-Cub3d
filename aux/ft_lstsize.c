/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:16 by dicarval          #+#    #+#             */
/*   Updated: 2025/03/14 15:51:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize_input(t_input *n)
{
	size_t	i;
	t_input	*tmp;

	i = 0;
	tmp = n;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

size_t	ft_lstsize_env(t_env *n)
{
	size_t	i;
	t_env	*tmp;

	i = 0;
	tmp = n;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
