/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:08:21 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/27 21:36:25 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int ft_in_charset(char *charset, char c)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int check_one(t_game *game, int i, int j, int *player_count)
{
    if (i == 0 || i == game->length - 1 || j == 0 || j == game->width - 1)
        return (ft_in_charset("12", game->map[i][j]));
    if (game->map[i][j] == '2')
        return (ft_in_charset("12", game->map[i + 1][j]) && ft_in_charset("12", game->map[i][j + 1]));
    else if (game->map[i][j] == '0')
        return (ft_in_charset("01NSEW", game->map[i + 1][j]) && ft_in_charset("01NSEW", game->map[i][j + 1]));
    else if (ft_in_charset("NSEW", game->map[i][j]))
    {
        game->pos.x = j;
        game->pos.y = i;
        (*player_count)++;
        return (ft_in_charset("01", game->map[i + 1][j]) && ft_in_charset("01", game->map[i][j + 1]));
    }
    return (1);
}

int    check_map(t_game *game)
{
    int i;
    int j;
    int player_count;

    i = 0;
    player_count = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (!ft_in_charset("012NSEW", game->map[i][j]))
                return (0);
            if (!check_one(game, i, j, &player_count))
                return (printf("i:%d , j:%d\n", i, j), 0);
            j++;
        }
        i++;
    }
    return (player_count == 1);
}
