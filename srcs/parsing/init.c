/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:39 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/29 05:00:39 by pibosc           ###   ########.fr       */
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

void    display_misc(t_game *game)
{
    printf("NO : %s\n", game->textures[0]);
    printf("SO : %s\n", game->textures[1]);
    printf("WE : %s\n", game->textures[2]);
    printf("EA : %s\n", game->textures[3]);
    printf("C : %d, ", game->colors_c[1]);
    printf("%d, ", game->colors_c[2]);
    printf("%d\n", game->colors_c[3]);
    printf("F : %d, ", game->colors_f[1]);
    printf("%d, ", game->colors_f[2]);
    printf("%d\n", game->colors_f[3]);
}

void init_map(char *path, t_game *game)
{
    game->fd = open(path, O_RDONLY);
    if (game->fd == -1)
        panic(FILE_ERR);
    get_info_map(game);
    display_misc(game);
    display_tab(game->map->map);
}