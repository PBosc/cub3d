/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:09:11 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/28 00:01:16 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void set_texture(char *line, t_game *game)
{
    char **splitted;

    splitted = ft_split(line, ' ');
    if (!splitted || plen(splitted) != 2)     
        panic(MAP_ERR);
    if (!ft_strcmp(splitted[0], "NO") && game->textures[0])
        panic(MAP_ERR);
    if (!ft_strcmp(splitted[0], "SO") && game->textures[1])
        panic(MAP_ERR);
    if (!ft_strcmp(splitted[0], "WE") && game->textures[2])
        panic(MAP_ERR);
    if (!ft_strcmp(splitted[0], "EA") && game->textures[3])
        panic(MAP_ERR);
    if (!ft_strcmp(splitted[0], "NO"))
        game->textures[0] = ft_strdup(splitted[1]);
    if (!ft_strcmp(splitted[0], "SO"))
        game->textures[1] = ft_strdup(splitted[1]);
    if (!ft_strcmp(splitted[0], "WE"))
        game->textures[2] = ft_strdup(splitted[1]);
    if (!ft_strcmp(splitted[0], "EA"))
        game->textures[3] = ft_strdup(splitted[1]);
    free_tab(splitted);
}
