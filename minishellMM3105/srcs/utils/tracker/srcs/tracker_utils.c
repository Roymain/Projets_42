/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:50 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/07 21:09:50 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracker.h"

t_track	*ft_lstlasttracker(t_track *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_backtotrack(t_track **alst, t_track *news)
{
	t_track	*var;

	if (*alst)
	{
		var = ft_lstlasttracker(*alst);
		var->next = news;
	}
	else if (!*alst && news)
		*alst = news;
	else
		*alst = NULL;
}

t_track	*ft_lstnewtracker(void **content)
{
	t_track	*new;

	new = malloc(sizeof(t_track));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstdelonetracker(t_track *lst, void (*del)(void*))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

void	ft_lstcleartracker(t_track **lst, void (*del)(void *))
{
	t_track	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelonetracker(*lst, del);
		(*lst) = next;
	}
}
