/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <sumu.hyvonen@student.hive.fi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:41:21 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/29 15:48:50 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || *lst == NULL)
		return;
	t_list	*current = *lst;
	t_list	*next_node;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->content != NULL && del != NULL)
			del(current->content);
		free (current);
		current = next_node;
	}
	*lst = NULL;
}