/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:52:28 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:30 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_show_count(t_game *game, int j, int i)
{
	if (i < 0)
		return ;
	game->image.digit[1]->instances[i].enabled = 0;
	game->image.digit[2]->instances[i].enabled = 0;
	game->image.digit[3]->instances[i].enabled = 0;
	game->image.digit[4]->instances[i].enabled = 0;
	game->image.digit[5]->instances[i].enabled = 0;
	game->image.digit[6]->instances[i].enabled = 0;
	game->image.digit[7]->instances[i].enabled = 0;
	game->image.digit[8]->instances[i].enabled = 0;
	game->image.digit[9]->instances[i].enabled = 0;
	game->image.digit[0]->instances[i].enabled = 0;
	game->image.digit[j]->instances[i].enabled = 1;
}

void	ft_update_count(t_game *game, int num, int step)
{
	if (num >= 10)
		ft_update_count(game, num / 10, step - 1);
	ft_show_count(game, num % 10, step);
}

void	ft_display_number(mlx_t *mlx, t_game game, int i, t_image img)
{
	mlx_image_to_window(mlx, img.digit[1], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[2], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[3], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[4], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[5], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[6], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[7], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[8], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[9], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[0], game.y * SIZE, game.x * SIZE);
	img.digit[1]->instances[i].enabled = 0;
	img.digit[2]->instances[i].enabled = 0;
	img.digit[3]->instances[i].enabled = 0;
	img.digit[4]->instances[i].enabled = 0;
	img.digit[5]->instances[i].enabled = 0;
	img.digit[6]->instances[i].enabled = 0;
	img.digit[7]->instances[i].enabled = 0;
	img.digit[8]->instances[i].enabled = 0;
	img.digit[9]->instances[i].enabled = 0;
}
