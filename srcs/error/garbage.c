/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:45 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/24 16:49:57 by ybelatar         ###   ########.fr       */
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

t_garbage	*ft_lstlastt(t_garbage *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_garbage **lst, t_garbage *new)
{
	t_garbage	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlastt(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstclear(t_garbage **lst)
{
	t_garbage	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		cfree((*lst)->content);
        cfree(*lst);
		*lst = tmp;
	}
}

void    *gc(void *ptr, int i)
{
    static t_garbage *gb = NULL;

    
    if (i)
    {
		// if (!ptr)
		// 	gc(NULL, 0);
        ft_lstadd_back(&gb, ft_lstnew(ptr));
        return (ptr);
    }
    else
    {
        ft_lstclear(&gb);
        return (NULL);
    }
}