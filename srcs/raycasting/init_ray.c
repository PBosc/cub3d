/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:19:37 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/29 05:09:43 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width,
			mlx->height, "Cub3d");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	if (!mlx->mlx || !mlx->win || !mlx->win || !mlx->addr)
		return (panic("Fail in MLX"), false);
	return (true);
}

void	destroy_wall_images(t_mlx *mlx, t_map *map, const int ind)
{
	int	i;

	i = 1;
	mlx_destroy_image(mlx->mlx, map->textures[0].img);
	map->textures[0].img = NULL;
	while (i <= ind)
		mlx_destroy_image(mlx->mlx, map->textures[i++].img);
}

static bool	get_addresses_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		map->textures[i].addr = mlx_get_data_addr(map->textures[i].img,
				&(map->textures[i].bpp), &(map->textures[i].size_line),
				&(map->textures[i].endian));
		if (!map->textures[i].addr)
			return (false);
		++i;
	}
	return (true);
}
bool	get_textures_walls(t_mlx *mlx, t_map *map)
{
	map->textures[0].img = mlx_xpm_file_to_image(mlx->mlx, map->path_north,
			&(map->textures[0].width), &(map->textures[0].height));
	if (!map->textures[0].img)
		return (destroy_wall_images(mlx, map, 0), false);
	map->textures[1].img = mlx_xpm_file_to_image(mlx->mlx, map->path_south,
			&(map->textures[1].width), &(map->textures[1].height));
	if (!map->textures[1].img)
		return (destroy_wall_images(mlx, map, 1), false);
	map->textures[2].img = mlx_xpm_file_to_image(mlx->mlx, map->path_west,
			&(map->textures[2].width), &(map->textures[2].height));
	if (!map->textures[2].img)
		return (destroy_wall_images(mlx, map, 2), false);
	map->textures[3].img = mlx_xpm_file_to_image(mlx->mlx, map->path_east,
			&(map->textures[3].width), &(map->textures[3].height));
	if (!map->textures[3].img)
		return (destroy_wall_images(mlx, map, 3), false);
	map->textures[4].img = mlx_xpm_file_to_image(mlx->mlx,
			map->path_door_closed, &(map->textures[4].width),
			&(map->textures[4].height));
	if (!map->textures[4].img || !get_addresses_walls(map))
		return (destroy_wall_images(mlx, map, 4), false);
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

void	set_to_zero_player(t_game *game, t_player *player)
{
	set_pos(&player->pos, 0, 0);
	set_pos(&player->dir, -1, 0);
	set_pos(&player->plane, 0, 0.66);
	player->move_speed = 0.08;
	player->rot_speed = 0.03;
	player->w = false;
	player->a = false;
	player->s = false;
	player->d = false;
	player->r_key = false;
	player->l_key = false;
	player->angle = 0.0;
	game->player = player;
}

void	set_to_zero_mlx(t_game *game, t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->height = -1;
	mlx->width = -1;
	mlx->bpp = -1;
	mlx->size_line = -1;
	mlx->endian = -1;
	mlx->refresh = false;
	// mlx->minimap_colors[0] = 0xFFFFFF;
	// mlx->minimap_colors[1] = 0xFF0000;
	// mlx->minimap_colors[2] = 0xF07470;
	// mlx->minimap_colors[3] = 0xF6BDC0;
	game->mlx = mlx;
}

void	set_to_zero_map(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < 7)
		map->param_lines[i++] = -1;
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_east = NULL;
	map->path_west = NULL;
	map->path_door_closed = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->total_parameters = 0;
	map->height = 0;
	map->width = 0;
	map->start_coords[0] = -1;
	map->start_coords[1] = -1;
	map->start_direction = '\0';
	map->map = NULL;
	map->first_line_map = -1;
	map->textures[0].img = NULL;
	game->map = map;
}

int	put_image(t_game *game, t_mlx *mlx)
{
	move(game, mlx);
	if (mlx->refresh == false)
		return (1);
	caster(mlx, game->map, game->player);
	// minimap(mlx, game->map, game->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	if (door(game->map, game->player))
		mlx_string_put(mlx->mlx, mlx->win, mlx->width / 2.14,
			mlx->height / 3, 0xFFFFFF, "E to open");
	mlx->refresh = false;
	return (1);
}
bool	start_window(t_mlx *mlx, t_game *game)
{
	if (init(mlx) == false)
		return (false);
	if (!get_textures_walls(mlx, game->map))
		return (false);
	init_position(game->player, game->start_direction);
	mlx_hook(mlx->win, ON_DESTROY, NO_MASK, on_destroy, game);
	mlx_hook(mlx->win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, game);
	mlx_hook(mlx->win, ON_KEYRELEASE, KEYRELEASE_MASK, on_keyrelease, game);
	mlx_loop_hook(mlx->mlx, &put_image, game);
	mlx->refresh = true;
	put_image(game, mlx);
	mlx_loop(mlx->mlx);
	return (true);
}
