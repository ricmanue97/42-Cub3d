/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:46:30 by dicarval          #+#    #+#             */
/*   Updated: 2025/01/07 16:36:07 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_input	*ft_lstlast(t_input *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
