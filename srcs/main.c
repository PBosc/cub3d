/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:59 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/29 05:18:08 by pibosc           ###   ########.fr       */
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
	set_pos(&(player->pos), 3.5, 2.5);
	set_pos(&(player->dir), 0, -1);
	set_pos(&(player->plane), -0.80, 0);
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

int main (int ac, char **av)
{
    t_game *game;
	t_mlx	mlx;
	t_map	map;
	t_player	player;

    game = gc(malloc(sizeof(t_game)), 1);
	(void)ac;
	set_to_zero_map(game, &map);
	set_to_zero_player(game, &player);
	set_to_zero_mlx(game, &mlx);
	/*PARSING*/
	init_map(av[1], game);
	start_window(&mlx, game);
    //init_mlx(game);
    return (0);
}
