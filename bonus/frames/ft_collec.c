/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:56:55 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:29 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	reveal_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image.exit, x * SIZE, y * SIZE);
}

static void	frames_collec(t_game *game, int state)
{
	int	i;

	i = -1;
	while (++i < game->max_collec)
	{
		game->image.collec[0]->instances[i].enabled = 0;
		game->image.collec[1]->instances[i].enabled = 0;
		game->image.collec[2]->instances[i].enabled = 0;
		game->image.collec[3]->instances[i].enabled = 0;
		if (game->image.fground->instances[i].enabled != 1)
			game->image.collec[state]->instances[i].enabled = 1;
	}
}

void	ft_frames(t_game *game)
{
	static int	count = 0;

	if (count < FRAMEC)
		frames_collec(game, 0);
	else if (count < FRAMEC * 2)
		frames_collec(game, 1);
	else if (count < FRAMEC * 3)
		frames_collec(game, 2);
	else if (count < FRAMEC * 4)
		frames_collec(game, 3);
	else if (count < FRAMEC * 5)
		frames_collec(game, 2);
	else if (count < FRAMEC * 6)
		frames_collec(game, 1);
	else if (count == FRAMEC * 6)
	{
		frames_collec(game, 0);
		count = 0;
	}
	count++;
}

void	disable_collec(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->max_collec)
	{
		if (game->image.collec[0]->instances[i].x / SIZE == game->player_y
			&& game->image.collec[0]->instances[i].y / SIZE == game->player_x)
		{
			game->image.collec[1]->instances[i].enabled = 0;
			game->image.collec[2]->instances[i].enabled = 0;
			game->image.collec[3]->instances[i].enabled = 0;
			game->image.collec[0]->instances[i].enabled = 0;
			game->image.fground->instances[i].enabled = 1;
		}
	}
}
