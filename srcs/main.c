/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:59 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/27 21:48:35 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
TODO mettre les protections de malloc
*/
int check_extension(char *path)
{
    if (!path)
        return (0);
    return (!ft_strcmp(ft_strchr(path, '.'), ".cub"));
}

void    init_game(t_game *game)
{
    game->map = NULL;
    game->textures[0] = NULL;
    game->textures[1] = NULL;
    game->textures[2] = NULL;
    game->textures[3] = NULL;
    game->colors_c[0] = 0;
    game->colors_f[0] = 0;
    game->length = 0;
    game->width = 0;
}

int main (int ac, char **av)
{
    t_game *game;

    game = gc(malloc(sizeof(t_game)), 1);
    if (!game)
        panic(MALLOC_ERR);
    init_game(game);
    if (ac != 2 || !check_extension(av[1]))
        return (ft_dprintf(2, "Error\nWrong input\n"), 1);
    //init_game(game);
    init_map(av[1], game);
    //init_mlx(game);
    return (0);
}
