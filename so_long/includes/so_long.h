/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:51:08 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*	includes	*/
# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "fcntl.h"

/*	DONT TOUCH !!!	*/
# define SIZE 32

/*	KEY FOR MOVING, WSAD or ↑↓←→*/
# define UP1 MLX_KEY_UP
# define DOWN1 MLX_KEY_DOWN
# define LEFT1 MLX_KEY_LEFT
# define RIGHT1 MLX_KEY_RIGHT

# define UP2 MLX_KEY_W
# define DOWN2 MLX_KEY_S
# define LEFT2 MLX_KEY_A
# define RIGHT2 MLX_KEY_D

/*	MY TEXTURES	*/
typedef struct s_textures
{
	mlx_texture_t	*off_wall[4];
	mlx_texture_t	*off_corner[4];
	mlx_texture_t	*walls[3];
	mlx_texture_t	*corner[4];
	mlx_texture_t	*link[4];
	mlx_texture_t	*ground;
	mlx_texture_t	*fground;
	mlx_texture_t	*player[5];
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
	mlx_texture_t	*pac_man_exit[5];
}	t_textures;

/*	MY IMAGES	*/
typedef struct s_image
{
	mlx_image_t	*off_wall[4];
	mlx_image_t	*off_corner[4];
	mlx_image_t	*walls[3];
	mlx_image_t	*corner[4];
	mlx_image_t	*link[4];
	mlx_image_t	*ground;
	mlx_image_t	*fground;
	mlx_image_t	*player[5];
	mlx_image_t	*collec;
	mlx_image_t	*exit;
	mlx_image_t	*pac_man_exit[5];
}	t_image;

/*	GAMES VALUES	*/
typedef struct s_game
{
	mlx_t			*mlx;
	t_textures		textures;
	t_image			image;
	char			**map;
	int				error;
	int				x;
	int				y;
	int				max_x;
	int				max_y;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				nmb_exit;
	int				nmb_player;
	int				nmb_count;
	int				state;
	int				nmb_tex;
	int				max_collec;
	int				get_collec;
	int				moves;
	int				victory;
}	t_game;

/*	src/main.c	*/
void			reveal_exit(t_game *game, int x, int y);

/*	src/flood_fill.c	*/
int				ft_know_map(int fd);
void			fill(t_game *game, int row, int col, char **map);
char			**fill_map(t_game game);

/*	src/free_all.c	*/
void			free_map(char **map);
int				free_all(t_game *game);

/*	src/ft_check_map.c	*/
void			ft_know_size_map(t_game *game);
int				check_map(char *map);
int				ft_pars_walls(t_game game);

/*	src/ft_error.c	*/
int				ft_error(int n);
int				ft_args_error(int ac, char **av);

/*	src/ft_loops.c	*/
void			ft_screen_victory(t_game *game);

/*	src/ft_check_values.c	*/
int				ft_check_values(char c);
int				ft_parsing(t_game game);

/*	src/ft_show_textures.c	*/
void			ft_frames_of_player(mlx_t *mlx, t_game game, t_image *img);
void			ft_show_map(mlx_t *mlx, t_game game, char c);

/*	src/ft_walls.c	*/
void			ft_show_walls(mlx_t *mlx, t_game game, int x, int y);

/*	src/map.c	*/
void			ft_read_map(t_game *game, char *str);
int				ft_create_map(mlx_t *mlx, t_game *game);

/*	src/moves/ft_hook.c	*/
void			ft_hook(mlx_key_data_t key_data, t_game *game);

/*	src/moves/remove_collec.c	*/
void			disable_collec(t_game *game);

/*	src/textures/ft_load_png.c	*/
mlx_texture_t	*ft_load_png(const char *path, t_game *game);
void			ft_delete_texture(mlx_texture_t *tex);
int				ft_load_t(mlx_t *mlx, t_textures *tex, t_image *img, t_game *g);

/*	src/textures/ft_tex_data.c	*/
void			ft_textures_data(t_textures *tex, t_game *game);

/*	src/textures/ft_tex_player.c	*/
void			ft_textures_player(t_textures *tex, t_game *game);

/*	src/textures/ft_tex_walls.c	*/
void			ft_textures_walls(t_textures *tex, t_game *game);

#endif