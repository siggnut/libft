/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyvonen <sumu.hyvonen@student.hive.fi>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:33:00 by shyvonen          #+#    #+#             */
/*   Updated: 2024/04/29 15:40:44 by shyvonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return;

	if (lst->content != NULL && del != NULL)
	{
		del(lst->content);
	}
	free (lst);
}
