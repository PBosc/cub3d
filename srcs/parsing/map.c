/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:06:38 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/24 16:38:24 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map(t_game *game, char *line)
{
	while (line)
	{
		if (!*line)
			panic(MAP_ERR);
		game->map = gc(join_tab(game->map, line), 1);
		line = gc(get_next_line(game->fd), 1);
	}
	if (!game->map)
		panic(MAP_ERR);
}

int	is_texture_color(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (!ft_strncmp(line + i, "NO", 2) || !ft_strncmp(line + i, "SO", 2)
		|| !ft_strncmp(line + i, "EA", 2) || !ft_strncmp(line + i, "WE", 2)
		|| !ft_strncmp(line + i, "F", 1) || !ft_strncmp(line + i, "C", 1))
        return (1);
    return (0);
}

void	get_info_map(t_game *game)
{
	int		c;
	char	*line;

	line = gc(get_next_line(game->fd), 1);
	if (!line)
		panic(MAP_ERR);
	c = 0;
	while (line && *line != '1' && *line != ' ')
	{
		if (is_texture_color(line))
		{
			game->premap = gc(join_tab(game->premap, line), 1);
			if (!game->premap)
				panic(MALLOC_ERR);
			c++;
		}
		line = gc(get_next_line(game->fd), 1);
		if (!line)
			panic(MAP_ERR);
	}
	if (c != 6)
		panic(MAP_ERR);
	get_map(game, line);
	// check_map(game, c);
}
