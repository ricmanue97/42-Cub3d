/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:37:50 by ricmanue          #+#    #+#             */
/*   Updated: 2025/04/11 10:37:52 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_input	*ft_lstnew_cmd(char *cmd_stx)
{
	t_input	*new;

	new = (t_input *)malloc(sizeof(t_input));
	if (!new)
		return (NULL);
	new->syntax = cmd_stx;
	new->export_rline = cmd_stx;
	new->path = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->redir[0] = -1;
	new->redir[1] = -1;
	new->fd[0] = -1;
	new->fd[1] = -1;
	new->nsfd = NO;
	new->args = NULL;
	return (new);
}
