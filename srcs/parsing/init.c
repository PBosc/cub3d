/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:39 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/24 16:51:52 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void display_tab(char **tab)
{
	int i = 0;

	if (!tab)
		return ;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void init_map(char *path, t_game *game)
{
    game->fd = open(path, O_RDONLY);
    if (game->fd == -1)
        panic(FILE_ERR);
    get_info_map(game);
    display_tab(game->map);
    //get_textures(game);
    //get_colors(game);
}