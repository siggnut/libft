/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <shyvonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:41:21 by shyvonen          #+#    #+#             */
/*   Updated: 2024/05/02 15:52:41 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	if (!lst || !*lst)
		return ;
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
