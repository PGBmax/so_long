/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 19:10:22 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	ft_for_long(mlx_t *mlx, t_game game, mlx_image_t *img)
{
	int	s;

	s = SIZE;
	mlx_image_to_window(mlx, img, game.player_y * s, game.player_x * s);
}

void	ft_frames_of_player(mlx_t *mlx, t_game game, t_image *img)
{
	int	s;

	s = SIZE;
	mlx_image_to_window(mlx, img->player[1], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[2], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[3], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[4], -1 * s, -1 * s);
	ft_for_long(mlx, game, img->player[0]);
}

void	ft_show_map(mlx_t *mlx, t_game game, char c)
{
	static int	collec_i = 0;
	int			s;

	s = SIZE;
	if (c == '1')
		ft_show_walls(mlx, game, game.x, game.y);
	if (c == '0' || c == 'E' || c == 'P')
		mlx_image_to_window(mlx, game.image.ground, game.y * s, game.x * s);
	if (c == 'C')
	{
		mlx_image_to_window(mlx, game.image.fground, game.y * s, game.x * s);
		mlx_image_to_window(mlx, game.image.collec, game.y * s, game.x * s);
		game.image.fground->instances[collec_i].enabled = 0;
		collec_i++;
	}
}
