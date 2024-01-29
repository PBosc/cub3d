/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:41:33 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/29 05:11:57 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	up(t_game *game, t_mlx *mlx)
{
	int			index_x;
	int			index_y;

	mlx->refresh = true;
	index_x = game->player->pos.x + game->player->dir.x * game->player->move_speed;
	index_y = game->player->pos.y + game->player->dir.y * game->player->move_speed;
	if (game->map->map[(int)game->player->pos.y][index_x] == '0'
		|| game->map->map[(int)game->player->pos.y][index_x] == '3')
		game->player->pos.x += game->player->dir.x * game->player->move_speed;
	if (game->map->map[index_y][(int)game->player->pos.x] == '0'
		|| game->map->map[index_y][(int)game->player->pos.x] == '3')
		game->player->pos.y += game->player->dir.y * game->player->move_speed;
}

static void	left(t_game *game, t_mlx *mlx)
{
	double		new_x;
	double		new_y;

	mlx->refresh = true;
	new_x = game->player->pos.x + game->player->dir.y * game->player->move_speed;
	new_y = game->player->pos.y - game->player->dir.x * game->player->move_speed;
	if (new_y > 1 && new_y <= game->length - 1
		&& (game->map->map[(int)new_y][(int)game->player->pos.x] == '0'
		|| game->map->map[(int)new_y][(int)game->player->pos.x] == '3'))
		game->player->pos.y = new_y;
	if (new_x > 1 && new_x <= game->width - 1
		&& (game->map->map[(int)new_y][(int)new_x] == '0'
		|| game->map->map[(int)new_y][(int)new_x] == '3'))
		game->player->pos.x = new_x;
}

static void	down(t_game *game, t_mlx *mlx)
{
	int			index_x;
	int			index_y;

	mlx->refresh = true;
	index_x = game->player->pos.x - game->player->dir.x * game->player->move_speed;
	index_y = game->player->pos.y - game->player->dir.y * game->player->move_speed;
	if (game->map->map[(int)game->player->pos.y][index_x] == '0'
		|| game->map->map[(int)game->player->pos.y][index_x] == '3')
		game->player->pos.x -= game->player->dir.x * game->player->move_speed;
	if (game->map->map[index_y][(int)game->player->pos.x] == '0'
		|| game->map->map[index_y][(int)game->player->pos.x] == '3')
		game->player->pos.y -= game->player->dir.y * game->player->move_speed;
}
static void right(t_game *game, t_mlx *mlx)
{
	double		new_x;
	double		new_y;

	mlx->refresh = true;
	new_x = game->player->pos.x - game->player->dir.y * game->player->move_speed;
	new_y = game->player->pos.y + game->player->dir.x * game->player->move_speed;
	if (new_y > 1 && new_y <= game->length - 1
		&& (game->map->map[(int)new_y][(int)game->player->pos.x] == '0'
		|| game->map->map[(int)new_y][(int)game->player->pos.x] == '3'))
		game->player->pos.y = new_y;
	if (new_x > 1 && new_x <= game->width - 1
		&& (game->map->map[(int)new_y][(int)new_x] == '0'
		|| game->map->map[(int)new_y][(int)new_x] == '3'))
		game->player->pos.x = new_x;
}

void	move(t_game *game, t_mlx *mlx)
{
	if (game->player->w == true)
		up(game, mlx);
	if (game->player->a == true)
		left(game, mlx);
	if (game->player->s == true)
		down(game, mlx);
	if (game->player->d == true)
		right(game, mlx);
	if (game->player->r_key == true)
		r_key(mlx, game->player);
	if (game->player->l_key == true)
		l_key(mlx, game->player);
}