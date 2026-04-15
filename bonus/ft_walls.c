/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:37:52 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:45:26 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_block_walls_3(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x][y - 1] == '1' && (game.map[x][y + 1] == '1'
		|| game.map[x + 1][y] != '1'))
		mlx_image_to_window(mlx, game.image.walls[0], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else
		mlx_image_to_window(mlx, game.image.exit, y * SIZE, x * SIZE);
}

static void	ft_block_walls_2(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x - 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[3], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner[0], y * SIZE, x * SIZE);
	else if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.walls[1], y * SIZE, x * SIZE);
	else if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.walls[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && (game.map[x][y - 1] == '1'
		|| game.map[x][y + 1] == '1'))
		mlx_image_to_window(mlx, game.image.walls[0], y * SIZE, x * SIZE);
	else
		ft_block_walls_3(mlx, game, x, y);
}

static void	ft_block_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y - 1] == '1' && game.map[x - 1][y] == '1'
		&& game.map[x - 1][y + 1] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y - 1] == '1'
		&& game.map[x + 1][y] == '1' && game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.ground, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x + 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[3], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x - 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[0], y * SIZE, x * SIZE);
	else
		ft_block_walls_2(mlx, game, x, y);
}

static void	ft_link_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (y == game.max_x && x != game.max_y && x != 0
		&& (game.map[x - 1][y - 1] != '1' || game.map[x + 1][y - 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[1], y * SIZE, x * SIZE);
	if (y == 0 && x != game.max_y && x != 0
		&& (game.map[x - 1][y + 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[0], y * SIZE, x * SIZE);
	if (x == 0 && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1' && game.map[x][y + 1] == '1'
		&& (game.map[x + 1][y - 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[2], y * SIZE, x * SIZE);
	if (x == game.max_y && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1' && game.map[x][y + 1] == '1'
		&& (game.map[x - 1][y - 1] != '1' || game.map[x - 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[3], y * SIZE, x * SIZE);
	if (x != game.max_y && y != game.max_x && y != 0 && x != 0
		&& game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.walls[2], y * SIZE, x * SIZE);
}

void	ft_show_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_image_to_window(mlx, game.image.off_corner[2], y * SIZE, x * SIZE);
	if (x == 0 && y == game.max_x)
		mlx_image_to_window(mlx, game.image.off_corner[3], y * SIZE, x * SIZE);
	if (x == game.max_y && y == 0)
		mlx_image_to_window(mlx, game.image.off_corner[0], y * SIZE, x * SIZE);
	if (x == game.max_y && y == game.max_x)
		mlx_image_to_window(mlx, game.image.off_corner[1], y * SIZE, x * SIZE);
	if (y == 0 && x != 0 && x != game.max_y)
		mlx_image_to_window(mlx, game.image.off_wall[0], y * SIZE, x * SIZE);
	if (y == game.max_x && x != 0 && x != game.max_y)
		mlx_image_to_window(mlx, game.image.off_wall[1], y * SIZE, x * SIZE);
	if (x == 0 && y != 0 && y != game.max_x)
		mlx_image_to_window(mlx, game.image.off_wall[2], y * SIZE, x * SIZE);
	if (x == game.max_y && y != 0 && y != game.max_x)
		mlx_image_to_window(mlx, game.image.off_wall[3], y * SIZE, x * SIZE);
	if (x != 0 && x != game.max_y && y != 0 && y != game.max_x)
		ft_block_walls(mlx, game, x, y);
	ft_link_walls(mlx, game, x, y);
}
