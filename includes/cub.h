/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:02 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/23 18:43:09 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_pos
{
    double x;
    double y;
    double angle;
}   t_pos;

typedef struct s_param
{
    
}   t_param;

typedef struct s_game
{
    int fd;
    t_param *param;
    t_pos *pos;
    char **premap;
    char **map;
}   t_game;

typedef struct s_garbage
{
    void    *content;
    struct s_garbage *next;
}   t_garbage;




#endif CUB_H