/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:50:20 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 16:33:58 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_moves_blinky2(t_game *game, int i, int j)
{
	if (game->blinky_x != game->max_x && game->blinky_y != game->max_y
		&& check_x(game, game->blinky_x + 1, game->blinky_y) && j == 1)
	{
		game->blinky_x++;
		game->image.blinky[1]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[1]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != -1 && game->blinky_y != -1
		&& check_y(game, game->blinky_x, game->blinky_y - 1) && j == 0)
	{
		game->blinky_y--;
		game->image.blinky[2]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[2]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != game->max_x && game->blinky_y != game->max_y
		&& check_y(game, game->blinky_x, game->blinky_y + 1) && j == 1)
	{
		game->blinky_y++;
		game->image.blinky[3]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[3]->instances->y = game->blinky_x * SIZE;
	}
	else
		ft_moves_blinky(game, i + 1);
	if (game->blinky_x == game->player_x && game->blinky_y == game->player_y)
		game->victory = -1;
}

void	ft_moves_blinky(t_game *game, int i)
{
	int	j;

	j = rand() % 2;
	if (game->nmb_ghost[0] == 0 || i > 4)
	{
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
		return ;
	}
	game->image.blinky[0]->instances->x = -1 * SIZE;
	game->image.blinky[1]->instances->x = -1 * SIZE;
	game->image.blinky[2]->instances->x = -1 * SIZE;
	game->image.blinky[3]->instances->x = -1 * SIZE;
	game->image.blinky[4]->instances->x = -1 * SIZE;
	game->image.blinky[5]->instances->x = -1 * SIZE;
	if (game->blinky_x != -1 && game->blinky_y != -1
		&& check_x(game, game->blinky_x - 1, game->blinky_y) && j == 0)
	{
		game->blinky_x--;
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
	}
	else
		ft_moves_blinky2(game, i, j);
}

static void	ft_moves_clyde2(t_game *game, int i, int j)
{
	if (game->clyde_x != game->max_x && game->clyde_y != game->max_y
		&& check_x(game, game->clyde_x + 1, game->clyde_y) && j == 1)
	{
		game->clyde_x++;
		game->image.clyde[1]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[1]->instances->y = game->clyde_x * SIZE;
	}
	else if (game->clyde_x != -1 && game->clyde_y != -1
		&& check_y(game, game->clyde_x, game->clyde_y - 1) && j == 0)
	{
		game->clyde_y--;
		game->image.clyde[2]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[2]->instances->y = game->clyde_x * SIZE;
	}
	else if (game->clyde_x != game->max_x && game->clyde_y != game->max_y
		&& check_y(game, game->clyde_x, game->clyde_y + 1) && j == 1)
	{
		game->clyde_y++;
		game->image.clyde[3]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[3]->instances->y = game->clyde_x * SIZE;
	}
	else
		ft_moves_clyde(game, i + 1);
	if (game->clyde_x == game->player_x && game->clyde_y == game->player_y)
		game->victory = -1;
}

void	ft_moves_clyde(t_game *game, int i)
{
	int	j;

	j = rand() % 2;
	if (game->nmb_ghost[1] == 0 || i > 4)
	{
		game->image.clyde[0]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[0]->instances->y = game->clyde_x * SIZE;
		return ;
	}
	game->image.clyde[0]->instances->x = -1 * SIZE;
	game->image.clyde[1]->instances->x = -1 * SIZE;
	game->image.clyde[2]->instances->x = -1 * SIZE;
	game->image.clyde[3]->instances->x = -1 * SIZE;
	game->image.clyde[4]->instances->x = -1 * SIZE;
	game->image.clyde[5]->instances->x = -1 * SIZE;
	if (game->clyde_x != -1 && game->clyde_y != -1
		&& check_x(game, game->clyde_x - 1, game->clyde_y) && j == 0)
	{
		game->clyde_x--;
		game->image.clyde[0]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[0]->instances->y = game->clyde_x * SIZE;
	}
	else
		ft_moves_clyde2(game, i, j);
}
