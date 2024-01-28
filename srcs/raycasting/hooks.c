/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:38:11 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/28 03:36:19 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (exit(EXIT_SUCCESS), 1);
	if (keycode == XK_w)
		game->pressed_w = true;
	if (keycode == XK_a)
		game->pressed_a = true;
	if (keycode == XK_s)
		game->pressed_s = true;
	if (keycode == XK_d)
		game->pressed_d = true;
	// if (keycode == XK_e)
	// 	door_action(game->display, game->map, game->camera);
	if (keycode == XK_Left)
		game->pressed_left = true;
	if (keycode == XK_Right)
		game->pressed_right = true;
	return (1);
}

int	on_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (exit(EXIT_SUCCESS), 1);
	if (keycode == XK_w)
		game->pressed_w = false;
	if (keycode == XK_a)
		game->pressed_a = false;
	if (keycode == XK_s)
		game->pressed_s = false;
	if (keycode == XK_d)
		game->pressed_d = false;
	if (keycode == XK_Left)
		game->pressed_left = false;
	if (keycode == XK_Right)
		game->pressed_right = false;
	return (1);
}