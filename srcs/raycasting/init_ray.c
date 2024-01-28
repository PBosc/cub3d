/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:19:37 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/28 04:39:37 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH,
			HEIGHT, "Cub3d");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img.pixels_ptr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	if (!mlx->mlx || !mlx->win || !mlx->win || !mlx->addr)
		return (panic("Fail in MLX"), false);
	return (true);
}

static void	init_position(t_player *player, char start_dir)
{
	const double	old_dir_x = player->dir.x;
	const double	old_plane_x = player->plane.x;
	double			to_add;

	if (start_dir == 'W')
		to_add = 0;
	else if (start_dir == 'N')
		to_add = 3 * PI / 2;
	else if (start_dir == 'S')
		to_add = PI / 2;
	else
		to_add = PI;
	player->dir.x = old_dir_x * cos(-to_add)
		- player->dir.y * sin(-to_add);
	player->dir.y = old_dir_x * sin(-to_add)
		+ player->dir.y * cos(-to_add);
	player->plane.x = old_plane_x * cos(-to_add)
		- player->plane.y * sin(-to_add);
	player->plane.y = old_plane_x * sin(-to_add)
		+ player->plane.y * cos(-to_add);
}

int	put_image(t_game *game, t_mlx *mlx)
{
	t_img	img;

	move(game);
	if (game->refresh == false)
		return (1);
	printf("caster\n");
	caster(game, game->player, mlx);
	printf("put_image\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img.img_ptr, 0, 0);
	game->refresh = false;
	return (1);
}
bool	start_window(t_mlx *mlx, t_game *game)
{
	if (init(mlx) == false)
		return (false);
	init_position(game->player, 'W');
	// mlx_hook(mlx->win, ON_DESTROY, NO_MASK, on_destroy, game);
	mlx_hook(mlx->win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, game);
	mlx_hook(mlx->win, ON_KEYRELEASE, KEYRELEASE_MASK, on_keyrelease, game);
	mlx_loop_hook(mlx->mlx, &put_image, game);
	// get_textures(mlx, game->map);
	game->refresh = true;
	put_image(game, mlx);
	mlx_loop(mlx->mlx);
	return (true);
}
