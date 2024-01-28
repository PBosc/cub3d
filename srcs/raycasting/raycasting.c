/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:49:44 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/28 04:28:36 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_caster(t_game *game, t_player *player, int x)
{
	(void)game;
	player->player_x = -(2 * x / (double)WIDTH - 1);
	set_pos(&(player->ray_dir),
		player->dir.x + player->plane.x * player->player_x,
		player->dir.y + player->plane.y * player->player_x);
	player->map_x = (int)player->pos.x;
	player->map_y = (int)player->pos.y;
	if (player->ray_dir.x == 0 && player->ray_dir.y == 0)
		set_pos(&(player->delta_dist), DBL_MAX, DBL_MAX);
	else if (player->ray_dir.x == 0 && player->ray_dir.y != 0)
		set_pos(&(player->delta_dist), DBL_MAX,
			fabs(1 / player->ray_dir.y));
	else if (player->ray_dir.x != 0 && player->ray_dir.y == 0)
		set_pos(&(player->delta_dist), fabs(1 / player->ray_dir.x),
			DBL_MAX);
	else
		set_pos(&(player->delta_dist), fabs(1 / player->ray_dir.x),
			fabs(1 / player->ray_dir.y));
}

static void	player_step(t_player *player)
{
	if (player->ray_dir.x < 0)
	{
		player->step_x = -1;
		player->side_dist.x = (player->pos.x - player->map_x)
			* player->delta_dist.x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist.x = (player->map_x + 1.0 - player->pos.x)
			* player->delta_dist.x;
	}
	if (player->ray_dir.y < 0)
	{
		player->step_y = -1;
		player->side_dist.y = (player->pos.y - player->map_y)
			* player->delta_dist.y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist.y = (player->map_y + 1.0 - player->pos.y)
			* player->delta_dist.y;
	}
}

static void	hit_detection(t_player *player, t_game *game,
	int *hit)
{
	if (player->side_dist.x < player->side_dist.y)
	{
		player->side_dist.x += player->delta_dist.x;
		player->map_x += player->step_x;
		player->side = 0;
	}
	else
	{
		player->side_dist.y += player->delta_dist.y;
		player->map_y += player->step_y;
		player->side = 1;
	}
	if (player->map_y >= game->length || player->map_x >= game->width
		|| player->map_y < 0 || player->map_x < 0
		|| game->map[player->map_y][player->map_x] == '1')
		*hit = 1;
}

void	caster(t_game *game, t_player *player, t_mlx *mlx)
{
	int	x;
	int	hit;

	x = 0;
	printf("width: %d\n", WIDTH);
	while (x < WIDTH + 1)
	{
		init_caster(game, player, x);
		player_step(player);
		hit = 0;
		while (hit == 0)
			hit_detection(player, game, &hit);
		if (player->side == 0)
			player->perp_wall_dist = player->side_dist.x - player->delta_dist.x;
		else
			player->perp_wall_dist = player->side_dist.y - player->delta_dist.y;
		if (player->perp_wall_dist == 0)
			player->perp_wall_dist = 1;
		printf("x: %d\n", x);
		draw_Vline(mlx, player, x);
		printf("x: %d\n", x);
		++x;
	}
}