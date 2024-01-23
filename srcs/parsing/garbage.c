/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:45 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/16 16:43:05 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_garbage	*ft_lstnew(void *content)
{
	t_garbage	*lst;

	lst = malloc(sizeof(t_garbage));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_garbage **lst, t_garbage *new)
{
	t_garbage	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstclear(t_garbage **lst)
{
	t_garbage	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(lst->content);
        free(lst);
		*lst = tmp;
	}
}

void    *garbage_collector(void *ptr, int i)
{
    static *t_garbage gb = NULL;
    
    if (i)
    {
        ft_lstadd_back(&gb, ft_lstnew(ptr));
        return (ptr);
    }
    else
    {
        ft_lstclear(&gb);
        return (NULL);
    }
}