#include <so_long_bonus.h>

# define CLYDE_FLEE_DIST 4

static int	ft_moves_blinky2(t_game *game, int *order, int k)
{
	if (k > 3)
		return (0);
	if (order[k] == 0 && game->blinky_x != -1
		&& check_x(game, game->blinky_x - 1, game->blinky_y))
		game->blinky_x--;
	else if (order[k] == 1 && game->blinky_x != game->max_x
		&& check_x(game, game->blinky_x + 1, game->blinky_y))
		game->blinky_x++;
	else if (order[k] == 2 && game->blinky_y != -1
		&& check_y(game, game->blinky_x, game->blinky_y - 1))
		game->blinky_y--;
	else if (order[k] == 3 && game->blinky_y != game->max_y
		&& check_y(game, game->blinky_x, game->blinky_y + 1))
		game->blinky_y++;
	else
		return (ft_moves_blinky2(game, order, k + 1));
	game->image.blinky[order[k]]->instances->x = game->blinky_y * SIZE;
	game->image.blinky[order[k]]->instances->y = game->blinky_x * SIZE;
	if (game->blinky_x == game->player_x && game->blinky_y == game->player_y)
		game->victory = -1;
	return (1);
}

void	ft_moves_blinky(t_game *game, int i)
{
	int	order[4];
	int	dx;
	int	dy;

	(void)i;
	if (game->nmb_ghost[0] == 0)
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
	dx = game->player_x - game->blinky_x;
	dy = game->player_y - game->blinky_y;
	ft_ghost_priority(dx, dy, order);
	if (ft_moves_blinky2(game, order, 0) == 0)
	{
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
	}
}

static int	ft_moves_clyde2(t_game *game, int *order, int k)
{
	if (k > 3)
		return (0);
	if (order[k] == 0 && game->clyde_x != -1
		&& check_x(game, game->clyde_x - 1, game->clyde_y))
		game->clyde_x--;
	else if (order[k] == 1 && game->clyde_x != game->max_x
		&& check_x(game, game->clyde_x + 1, game->clyde_y))
		game->clyde_x++;
	else if (order[k] == 2 && game->clyde_y != -1
		&& check_y(game, game->clyde_x, game->clyde_y - 1))
		game->clyde_y--;
	else if (order[k] == 3 && game->clyde_y != game->max_y
		&& check_y(game, game->clyde_x, game->clyde_y + 1))
		game->clyde_y++;
	else
		return (ft_moves_clyde2(game, order, k + 1));
	game->image.clyde[order[k]]->instances->x = game->clyde_y * SIZE;
	game->image.clyde[order[k]]->instances->y = game->clyde_x * SIZE;
	if (game->clyde_x == game->player_x && game->clyde_y == game->player_y)
		game->victory = -1;
	return (1);
}

void	ft_moves_clyde(t_game *game, int i)
{
	int	order[4];
	int	dx;
	int	dy;

	(void)i;
	if (game->nmb_ghost[1] == 0)
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
	dx = game->player_x - game->clyde_x;
	dy = game->player_y - game->clyde_y;
	if (ft_abs(dx) + ft_abs(dy) < CLYDE_FLEE_DIST)
		ft_ghost_flee(&dx, &dy);
	ft_ghost_priority(dx, dy, order);
	if (ft_moves_clyde2(game, order, 0) == 0)
	{
		game->image.clyde[0]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[0]->instances->y = game->clyde_x * SIZE;
	}
}