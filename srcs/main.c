/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:59 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/28 03:16:30 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
TODO mettre les protections de malloc
*/
int check_extension(char *path)
{
    if (!path)
        return (0);
    return (!ft_strcmp(ft_strchr(path, '.'), ".cub"));
}

t_player	*init_player()
{
	t_player	*player;

	player = gc(malloc(sizeof(t_player)), 1);
	set_pos(&(player->pos), 35, 14);
	set_pos(&(player->dir), -1, 0);
	set_pos(&(player->plane), 0, 0.66);
	player->player_x = 0;
	player->map_x = 0;
	player->map_y = 0;
	player->step_x = 0;
	player->step_y = 0;
	set_pos(&(player->side_dist), 0, 0);
	set_pos(&(player->delta_dist), 0, 0);
	player->perp_wall_dist = 0;
	player->side = 0;
	return (player);
}

void    init_game(t_game *game)
{
	game->player = init_player();
    game->map = NULL;
    game->textures[0] = NULL;
    game->textures[1] = NULL;
    game->textures[2] = NULL;
    game->textures[3] = NULL;
    game->colors_c[0] = 0;
    game->colors_f[0] = 0;
    game->length = 0;
    game->width = 0;
	game->refresh = false;
	game->pressed_a = false;
	game->pressed_d = false;
	game->pressed_w = false;
	game->pressed_s = false;
	game->pressed_left = false;
	game->pressed_right = false;
}

int main (int ac, char **av)
{
    t_game *game;
	t_mlx	mlx;

    game = gc(malloc(sizeof(t_game)), 1);
	(void)ac;
    if (!game)
        panic(MALLOC_ERR);
    init_game(game);
	// printf("ac: %d\n", ac);
    init_map(av[1], game);
	start_window(&mlx, game);
    //init_mlx(game);
    return (0);
}
