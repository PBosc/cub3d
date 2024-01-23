/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:06:38 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/23 20:28:16 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void get_map(t_game *game, int c, char *line)
{
    while (line)
    {
        if (!*line)
            panic(MAP_ERR);
        game->map = gc(join_tab(game->map, line));
        line = gc(get_next_line(game->fd), 1);
    }
    if (!game->map)
        panic(MAP_ERR);
}

void check_map(t_game *game)
{
    if ()
        panic(MAP_ERR);
}

void get_info_map(t_game *game)
{
    int c;
    char *line;

    line = gc(get_next_line(game->fd), 1);
    if (!line)
        panic(MAP_ERR);
    c = 0;
    while (line && *line != '1' && *line != ' ')
    {
        if (is_texture_color(line))
        {
            game->premap = gc(join_tab(game->file, line));
            if (!game->file)
                panic(MALLOC_ERR);
            c++;
        }
        line = gc(get_next_line(game->fd), 1);
        if (!line)
            panic(MAP_ERR);
    }
    if (!check_c(c))
        panic(MAP_ERR);
    get_map(game, c, line);
    check_map(game);
}
