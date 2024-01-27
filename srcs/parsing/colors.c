/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:08:38 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/27 18:33:36 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int only_num(char *color)
{
    int i;

    i = 0;
    while (color[i])
    {
        if (!('0' <= color[i] && color[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int in_range(char *color)
{
    return (0 <= ft_atoi(color) && ft_atoi(color) <= 255);
}

int	check_args_colors(char **colors)
{
	if (!only_num(colors[0]) || !only_num(colors[1]) || !only_num(colors[2]))
		return (0);
	if (!in_range(colors[0]) || !in_range(colors[1]) || !in_range(colors[2]))
        return (0);
    return (1);
}

void	get_color(char *line, int a, t_game *game)
{
	char	**splitted;

	splitted = ft_split(line, ',');
	if (!splitted || plen(splitted) != 3)
		panic(MAP_ERR);
	if (!check_args_colors(splitted))
		panic(MAP_ERR);
	if (a)
	{
		game->colors_c[0] = 1;
		game->colors_c[1] = ft_atoi(splitted[0]);
		game->colors_c[2] = ft_atoi(splitted[1]);
		game->colors_c[3] = ft_atoi(splitted[2]);
	}
	else
	{
		game->colors_f[0] = 1;
		game->colors_f[1] = ft_atoi(splitted[0]);
		game->colors_f[2] = ft_atoi(splitted[1]);
		game->colors_f[3] = ft_atoi(splitted[2]);
	}
	free_tab(splitted);
}

void	set_colors(char *line, t_game *game)
{
	char **splitted;

	splitted = ft_split(line, ' ');
	if (!splitted || plen(splitted) != 2)
		panic(MAP_ERR);
	if (!ft_strcmp(splitted[0], "C") && game->colors_c[0])
		panic(MAP_ERR);
	if (!ft_strcmp(splitted[0], "F") && game->colors_f[0])
		panic(MAP_ERR);
	if (!ft_strcmp(splitted[0], "C"))
		get_color(splitted[1], 1, game);
	if (!ft_strcmp(splitted[0], "F"))
		get_color(splitted[1], 0, game);
	free_tab(splitted);
}