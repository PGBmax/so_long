/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ghost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:09:21 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 16:23:35 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	check_x(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1' || game->map[x][y] == 'E')
		return (0);
	if (x == game->inky_x || x == game->pinky_x
		|| x == game->clyde_x || x == game->blinky_x)
		return (0);
	return (1);
}

int	check_y(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1' || game->map[x][y] == 'E')
		return (0);
	if (y == game->inky_y || y == game->pinky_y
		|| y == game->clyde_y || y == game->blinky_y)
		return (0);
	return (1);
}

static void	ft_frames_mobs(t_game *game, int n)
{
	game->image.blinky[4]->instances->x = -1 * SIZE;
	game->image.pinky[4]->instances->x = -1 * SIZE;
	game->image.inky[4]->instances->x = -1 * SIZE;
	game->image.clyde[4]->instances->x = -1 * SIZE;
	game->image.blinky[5]->instances->x = -1 * SIZE;
	game->image.pinky[5]->instances->x = -1 * SIZE;
	game->image.inky[5]->instances->x = -1 * SIZE;
	game->image.clyde[5]->instances->x = -1 * SIZE;
	game->image.blinky[6]->instances->x = -1 * SIZE;
	game->image.pinky[6]->instances->x = -1 * SIZE;
	game->image.inky[6]->instances->x = -1 * SIZE;
	game->image.clyde[6]->instances->x = -1 * SIZE;
	game->image.inky[n]->instances->x = game->inky_y * SIZE;
	game->image.inky[n]->instances->y = game->inky_x * SIZE;
	game->image.blinky[n]->instances->x = game->blinky_y * SIZE;
	game->image.blinky[n]->instances->y = game->blinky_x * SIZE;
	game->image.pinky[n]->instances->x = game->pinky_y * SIZE;
	game->image.pinky[n]->instances->y = game->pinky_x * SIZE;
	game->image.clyde[n]->instances->x = game->clyde_y * SIZE;
	game->image.clyde[n]->instances->y = game->clyde_x * SIZE;
}

void	frame_mobs(t_game *game)
{
	static int	count = 0;

	if (count < FRAMEG)
		ft_frames_mobs(game, 4);
	else if (count < FRAMEG * 2)
		ft_frames_mobs(game, 5);
	else if (count < FRAMEG * 3)
		ft_frames_mobs(game, 6);
	else if (count < FRAMEG * 4)
		ft_frames_mobs(game, 5);
	else if (count == FRAMEG * 4)
	{
		ft_frames_mobs(game, 4);
		count = 0;
	}
	count++;
}
