/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:41:33 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/28 03:39:59 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	up(t_game *game)
{
	int			index_x;
	int			index_y;

	game->refresh = true;
	printf("game->player->pos.x = %f\n", game->player->pos.x);
	printf("game->player->pos.y = %f\n", game->player->pos.y);
	index_x = game->player->pos.x + game->player->dir.x * 0.08;
	index_y = game->player->pos.y + game->player->dir.y * 0.08;
	if (!((int)game->player->pos.y <= 0 || index_x <= 0
			|| game->player->pos.y >= game->length - 1
			|| index_x >= game->width - 1))
		game->player->pos.x += game->player->dir.x * 0.08;
	if (!(index_y <= 0 || (int)game->player->pos.x <= 0
			|| index_y >= game->length - 1
			|| (int)game->player->pos.x >= game->width - 1))
		game->player->pos.y += game->player->dir.y * 0.08;
	printf("game->player->pos.x = %f\n", game->player->pos.x);
	printf("game->player->pos.y = %f\n", game->player->pos.y);
}

static void	left(t_game *game)
{
	double		new_x;
	double		new_y;

	game->refresh = true;
	new_x = game->player->pos.x + game->player->dir.y * 0.08;
	new_y = game->player->pos.y - game->player->dir.x * 0.08;
	if (new_y > 1 && new_y <= /*map->height*/ 14 - 1)
		game->player->pos.y = new_y;
	if (new_x > 1 && new_x <= /*map->width*/ 35 - 1)
		game->player->pos.x = new_x;
}

static void	down(t_game *game)
{
	int			index_x;
	int			index_y;

	game->refresh = true;
	index_x = game->player->pos.x - game->player->dir.x * 0.08;
	index_y = game->player->pos.y - game->player->dir.y * 0.08;
	if (!((int)game->player->pos.y <= 0 || index_x <= 0
			|| game->player->pos.y >= /*map->height*/ 14 - 1
			|| index_x >= /*map->width*/ 35 - 1))
		game->player->pos.x -= game->player->dir.x * 0.08;
	if (!(index_y <= 0 || (int)game->player->pos.x <= 0
			|| index_y >= /*map->height*/ 14 - 1
			|| (int)game->player->pos.x >= /*map->width*/ 35 - 1))
		game->player->pos.y -= game->player->dir.y * 0.08;
}
static void right(t_game *game)
{
	double		new_x;
	double		new_y;

	game->refresh = true;
	new_x = game->player->pos.x - game->player->dir.y * 0.08;
	new_y = game->player->pos.y + game->player->dir.x * 0.08;
	if (new_y > 1 && new_y <= /*map->height*/ 14 - 1)
		game->player->pos.y = new_y;
	if (new_x > 1 && new_x <= /*map->width*/ 35 - 1)
		game->player->pos.x = new_x;
}

void	move(t_game *game)
{
	if (game->pressed_w == true)
		up(game);
	if (game->pressed_a == true)
		left(game);
	if (game->pressed_s == true)
		down(game);
	if (game->pressed_d == true)
		right(game);
	// if (game->pressed_right == true)
	// 	rot_right(game);
	// if (game->pressed_left == true)
	// 	rot_left(game);
}