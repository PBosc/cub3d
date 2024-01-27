/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:55:13 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/27 20:00:54 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    new_line(t_game *game, int i)
{
    char *res;
    int j;

    res = gc(malloc(game->width + 1), 1);
    if (!res)
        panic(MALLOC_ERR);
    j = 0;
    while (j < ft_strlen(game->map[i]))
    {
        if (game->map[i][j] == ' ')
            res[j] = '2';
        else
            res[j] = game->map[i][j];
        j++;
    }
    while (j < game->width)
        res[j++] = '2';
    // cfree(game->map[i]);
    game->map[i] = res;
}

void    format_line(t_game *game, int i)
{
    int j;

    j = 0;
    while (j < game->width)
    {
        if (game->map[i][j] == ' ')
            game->map[i][j] = '2';
        j++;
    }
}

void    pre_format_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) < game->width)
            new_line(game, i);
        else
            format_line(game, i);
        i++;
    }
}




void format_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '2')
                game->map[i][j] = '1';
            j++;
        }
        i++;
    }
}