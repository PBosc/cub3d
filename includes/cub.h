/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:02 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/24 16:41:13 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <ft_dprintf.h>
# include <get_next_line.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MALLOC_ERR "Malloc error\n"
# define FILE_ERR "File error\n"
# define MAP_ERR "Map error\n"

typedef struct s_pos
{
	double				x;
	double				y;
	double				angle;
}						t_pos;

typedef struct s_param
{
}						t_param;

typedef struct s_game
{
	int					fd;
	t_param				*param;
	t_pos				*pos;
	char				**premap;
	char				**map;
}						t_game;

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
}						t_garbage;

/*Parsing*/

void					init_map(char *path, t_game *game);
void					get_info_map(t_game *game);

/*Utils*/

char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s);
char					**join_tab(char **map, char *str);
int						ft_strlen(const char *str);
char					**ft_copy(char **map);
int						plen(char **map);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

/*Garbage collector*/

void					*gc(void *ptr, int i);

/*Free and exit*/

void					panic(char *message);
void					cfree(void *ptr);

#endif