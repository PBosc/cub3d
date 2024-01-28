/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 01:33:43 by pibosc            #+#    #+#             */
/*   Updated: 2024/01/28 04:31:40 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	init_line(t_line *line,
		t_player *player, const int line_height)
{
	line->draw_start = -line_height / 2 + HEIGHT / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line_height / 2 + HEIGHT / 2;
	if (line->draw_end >= HEIGHT)
		line->draw_end = HEIGHT - 1;
	// line->texture_number = select_texture(player);
	if (player->side == 0)
		line->wall_x = player->pos.y + player->perp_wall_dist
			* player->ray_dir.y;
	else
		line->wall_x = player->pos.x + player->perp_wall_dist
			* player->ray_dir.x;
	line->wall_x -= floor((line->wall_x));
	// line->texture_x = (int)(line->wall_x * (double)TEXTURE_WIDTH);
	// if (player->side == 0 && player->ray_dir.x > 0)
	// 	line->texture_x = TEXTURE_WIDTH - line->texture_x - 1;
	// if (player->side == 1 && player->ray_dir.y < 0)
	// 	line->texture_x = TEXTURE_WIDTH - line->texture_x - 1;
	// line->step = 1.0 * TEXTURE_HEIGHT / line_height;
	// line->texture_pos = (line->draw_start - HEIGHT
	// 		/ 2 + line_height / 2) * line->step;
}

void	draw_Vline(t_mlx *mlx, t_player *player, int x)
{
	const int		line_height = (int)(HEIGHT
			/ player->perp_wall_dist);
	int				y;
	t_line		line;

	init_line(&line, player, line_height);
	y = 0;
	printf("y = %d\n", y);
	printf("line.draw_start = %d\n", line.draw_start);
	printf("line.draw_end = %d\n", line.draw_end);
	while (y < line.draw_start)
		my_pixel_put((int)x, (int)y++, &mlx->img, RED);
	y = line.draw_start;
	while (y < line.draw_end)
	{
		// line.texture_y = (int)line.texture_pos & (TEXTURE_HEIGHT - 1);
		// line.texture_pos += line.step;
		// line.color = get_color(map, line.texture_number, line.texture_x,
		// 		line.texture_y);
		// if (player->side == 1)
		// 	line.color = (line.color >> 1) & 8355711;
		my_pixel_put((int)x, (int)y, &mlx->img, BLUE);
		++y;
	}
	y = line.draw_end;
	while (y < HEIGHT)
		my_pixel_put((int)x, (int)y++, &mlx->img, GREEN);
}