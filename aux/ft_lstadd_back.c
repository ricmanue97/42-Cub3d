/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:50:30 by dicarval          #+#    #+#             */
/*   Updated: 2025/04/30 11:51:39 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back_cmd(t_input **lst, t_input *new)
{
	t_input	*last;

	if (!lst || !new)
		return (UNSUCCESS);
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	new->pid = -1;
	return (SUCCESS);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast_env(*lst);
		last->next = new;
		new->prev = last;
	}
}
