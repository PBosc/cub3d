/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:02 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/28 03:23:55 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <limits.h>
# include <float.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
// # include "mlx_int.h"

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_MOUSEPRESS 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L
# define KEYRELEASE_MASK 2L
# define BUTTONPRESS_MASK 4L
# define CURSOR_RADIUS 10

# define PI 3.14159265358979323846
# define MALLOC_ERR "Malloc error\n"
# define FILE_ERR "File error\n"
# define MAP_ERR "Map error\n"

# define WIDTH 1280
# define HEIGHT 720
#define BLACK       		0x000000
#define WHITE       		0xFFFFFF
#define RED         		0xFF0000
#define GREEN       		0x00FF00
#define BLUE        		0x0000FF
#define MAGENTA_BURST   	0xFF00FF
#define LIME_SHOCK      	0xCCFF00
#define NEON_ORANGE     	0xFF6600
#define PSYCHEDELIC_PURPLE 	0x660066
#define AQUA_DREAM      	0x33CCCC
#define HOT_PINK        	0xFF66B2
#define ELECTRIC_BLUE   	0x0066FF
#define LAVA_RED        	0xFF3300

typedef struct s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct s_param
{
}						t_param;

typedef struct s_line
{
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	int				texture_number;
	double			wall_x;
	int				texture_x;
	int				texture_y;
	double			texture_pos;
	double			step;
}					t_line;

typedef struct s_player
{
	double		player_x;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	t_pos		pos;
	t_pos		dir;
	t_pos		plane;
	t_pos		ray_dir;
	t_pos		side_dist;
	t_pos		delta_dist;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_game
{
	int					fd;
	t_player			*player;
	char				**map;
	char				start_direction;
	int					length;
	int					width;
	bool				pressed_w;
	bool				pressed_a;
	bool				pressed_s;
	bool				pressed_d;
	bool				pressed_left;
	bool				pressed_right;
	char				*textures[4];
	int					colors_c[4];
	int					colors_f[4];
	bool				refresh;
}						t_game;

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
}						t_garbage;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	void		*addr;
	int			height;
	int			width;
	int			bpp;
	int			size_line;
	int			endian;
	bool		refresh;
}				t_mlx;

/*Parsing*/

void					init_map(char *path, t_game *game);
void					get_info_map(t_game *game);
void					set_colors(char *line, t_game *game);
void					set_texture(char *line, t_game *game);
void					pre_format_map(t_game *game);
void					format_map(t_game *game);
int						check_map(t_game *game);

/*Utils*/

char					*ft_strchr(const char *s, int c);
int						ft_dprintf(int fd, const char *str, ...);
char					*get_next_line(int fd);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s);
char					**join_tab(char **map, char *str);
int						ft_strlen(const char *str);
char					**ft_copy(char **map);
int						plen(char **map);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
void					skip_spaces(char *line, int *i);
int						plen(char **map);
int						ft_atoi(const char *str);
int						max(int a, int b);
char					**ft_split(char const *s, char c);

int						first_last_line(t_game *game);
void					display_tab(char **tab);
int						check_line(t_game *game);
int						first_last_inline(char *line);
int						valid_char(char *line, int *player_count);
int						no_dups(t_game *game);

/*Garbage collector*/

void					*gc(void *ptr, int i);

/*Free and exit*/

void					panic(char *message);
void					cfree(void *ptr);
void					free_tab(char **tab);

/*Raycasting*/

void	set_pos(t_pos *pos, double x, double y);
void	draw_Vline(t_mlx *mlx, t_player *player, int x);
bool	start_window(t_mlx *mlx, t_game *game);
void	caster(t_game *game, t_player *player, t_mlx *mlx);

/*Hooks*/

int		on_keyrelease(int keycode, t_game *game);
int		on_keypress(int keycode, t_game *game);
void	move(t_game *game);

#endif