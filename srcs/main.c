/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:59 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/23 18:43:02 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_extension(char *str)
{
    if (!str)
        return (0);
    return (!ft_strcmp(ft_strchr(path, '.'), ".cub"));
}

void    init_game(t_game *game)
{
    game->premap = NULL;
    game->map = NULL;
}

int main (int ac, char **av)
{
    t_game *game;

    game = gc(malloc(sizeof(t_game)), 1);
    if (!game)
        panic(MALLOC_ERR);
    if (ac != 2 || !check_extension(av[1]))
        return (ft_dprintf("Error\nWrong input\n"), 1);
    init_game(game);
    init_map(av[1], game)
    init_mlx(game)
    return (0);
}