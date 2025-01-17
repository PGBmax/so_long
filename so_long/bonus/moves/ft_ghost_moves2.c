/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_moves2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:16:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 16:34:34 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_moves_inky2(t_game *game, int i, int j)
{
	if (game->inky_x != game->max_x && game->inky_y != game->max_y
		&& check_x(game, game->inky_x + 1, game->inky_y) && j == 1)
	{
		game->inky_x++;
		game->image.inky[1]->instances->x = game->inky_y * SIZE;
		game->image.inky[1]->instances->y = game->inky_x * SIZE;
	}
	else if (game->inky_x != -1 && game->inky_y != -1
		&& check_y(game, game->inky_x, game->inky_y - 1) && j == 0)
	{
		game->inky_y--;
		game->image.inky[2]->instances->x = game->inky_y * SIZE;
		game->image.inky[2]->instances->y = game->inky_x * SIZE;
	}
	else if (game->inky_x != game->max_x && game->inky_y != game->max_y
		&& check_y(game, game->inky_x, game->inky_y + 1) && j == 1)
	{
		game->inky_y++;
		game->image.inky[3]->instances->x = game->inky_y * SIZE;
		game->image.inky[3]->instances->y = game->inky_x * SIZE;
	}
	else
		ft_moves_inky(game, i + 1);
	if (game->inky_x == game->player_x && game->inky_y == game->player_y)
		game->victory = -1;
}

void	ft_moves_inky(t_game *game, int i)
{
	int	j;

	j = rand() % 2;
	if (game->nmb_ghost[3] == 0 || i > 4)
	{
		game->image.inky[0]->instances->x = game->inky_y * SIZE;
		game->image.inky[0]->instances->y = game->inky_x * SIZE;
		return ;
	}
	game->image.inky[0]->instances->x = -1 * SIZE;
	game->image.inky[1]->instances->x = -1 * SIZE;
	game->image.inky[2]->instances->x = -1 * SIZE;
	game->image.inky[3]->instances->x = -1 * SIZE;
	game->image.inky[4]->instances->x = -1 * SIZE;
	game->image.inky[5]->instances->x = -1 * SIZE;
	if (game->inky_x != -1 && game->inky_y != -1
		&& check_x(game, game->inky_x - 1, game->inky_y) && j == 0)
	{
		game->inky_x--;
		game->image.inky[0]->instances->x = game->inky_y * SIZE;
		game->image.inky[0]->instances->y = game->inky_x * SIZE;
	}
	else
		ft_moves_inky2(game, i, j);
}

static void	ft_moves_pinky2(t_game *game, int i, int j)
{
	if (game->pinky_x != game->max_x && game->pinky_y != game->max_y
		&& check_x(game, game->pinky_x + 1, game->pinky_y) && j == 1)
	{
		game->pinky_x++;
		game->image.pinky[1]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[1]->instances->y = game->pinky_x * SIZE;
	}
	else if (game->pinky_x != -1 && game->pinky_y != -1
		&& check_y(game, game->pinky_x, game->pinky_y - 1) && j == 0)
	{
		game->pinky_y--;
		game->image.pinky[2]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[2]->instances->y = game->pinky_x * SIZE;
	}
	else if (game->pinky_x != game->max_x && game->pinky_y != game->max_y
		&& check_y(game, game->pinky_x, game->pinky_y + 1) && j == 1)
	{
		game->pinky_y++;
		game->image.pinky[3]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[3]->instances->y = game->pinky_x * SIZE;
	}
	else
		ft_moves_pinky(game, i + 1);
	if (game->pinky_x == game->player_x && game->pinky_y == game->player_y)
		game->victory = -1;
}

void	ft_moves_pinky(t_game *game, int i)
{
	int	j;

	j = rand() % 2;
	if (game->nmb_ghost[2] == 0 || i > 4)
	{
		game->image.pinky[0]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[0]->instances->y = game->pinky_x * SIZE;
		return ;
	}
	game->image.pinky[0]->instances->x = -1 * SIZE;
	game->image.pinky[1]->instances->x = -1 * SIZE;
	game->image.pinky[2]->instances->x = -1 * SIZE;
	game->image.pinky[3]->instances->x = -1 * SIZE;
	game->image.pinky[4]->instances->x = -1 * SIZE;
	game->image.pinky[5]->instances->x = -1 * SIZE;
	if (game->pinky_x != -1 && game->pinky_y != -1
		&& check_x(game, game->pinky_x - 1, game->pinky_y) && j == 0)
	{
		game->pinky_x--;
		game->image.pinky[0]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[0]->instances->y = game->pinky_x * SIZE;
	}
	else
		ft_moves_pinky2(game, i, j);
}
