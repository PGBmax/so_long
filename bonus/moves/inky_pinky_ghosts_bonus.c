#include <so_long_bonus.h>

# define INKY_CHASE_DIST 6

static int	ft_moves_inky2(t_game *game, int *order, int k)
{
	if (k > 3)
		return (0);
	if (order[k] == 0 && game->inky_x != -1
		&& check_x(game, game->inky_x - 1, game->inky_y))
		game->inky_x--;
	else if (order[k] == 1 && game->inky_x != game->max_x
		&& check_x(game, game->inky_x + 1, game->inky_y))
		game->inky_x++;
	else if (order[k] == 2 && game->inky_y != -1
		&& check_y(game, game->inky_x, game->inky_y - 1))
		game->inky_y--;
	else if (order[k] == 3 && game->inky_y != game->max_y
		&& check_y(game, game->inky_x, game->inky_y + 1))
		game->inky_y++;
	else
		return (ft_moves_inky2(game, order, k + 1));
	game->image.inky[order[k]]->instances->x = game->inky_y * SIZE;
	game->image.inky[order[k]]->instances->y = game->inky_x * SIZE;
	if (game->inky_x == game->player_x && game->inky_y == game->player_y)
		game->victory = -1;
	return (1);
}

void	ft_moves_inky(t_game *game, int i)
{
	int	order[4];
	int	dx;
	int	dy;

	(void)i;
	if (game->nmb_ghost[3] == 0)
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
	dx = game->player_x - game->inky_x;
	dy = game->player_y - game->inky_y;
	if (ft_abs(dx) + ft_abs(dy) > INKY_CHASE_DIST)
		ft_ghost_patrol(game->max_x, game->max_y, &dx, &dy);
	ft_ghost_priority(dx, dy, order);
	if (ft_moves_inky2(game, order, 0) == 0)
	{
		game->image.inky[0]->instances->x = game->inky_y * SIZE;
		game->image.inky[0]->instances->y = game->inky_x * SIZE;
	}
}

static int	ft_moves_pinky2(t_game *game, int *order, int k)
{
	if (k > 3)
		return (0);
	if (order[k] == 0 && game->pinky_x != -1
		&& check_x(game, game->pinky_x - 1, game->pinky_y))
		game->pinky_x--;
	else if (order[k] == 1 && game->pinky_x != game->max_x
		&& check_x(game, game->pinky_x + 1, game->pinky_y))
		game->pinky_x++;
	else if (order[k] == 2 && game->pinky_y != -1
		&& check_y(game, game->pinky_x, game->pinky_y - 1))
		game->pinky_y--;
	else if (order[k] == 3 && game->pinky_y != game->max_y
		&& check_y(game, game->pinky_x, game->pinky_y + 1))
		game->pinky_y++;
	else
		return (ft_moves_pinky2(game, order, k + 1));
	game->image.pinky[order[k]]->instances->x = game->pinky_y * SIZE;
	game->image.pinky[order[k]]->instances->y = game->pinky_x * SIZE;
	if (game->pinky_x == game->player_x && game->pinky_y == game->player_y)
		game->victory = -1;
	return (1);
}

void	ft_moves_pinky(t_game *game, int i)
{
	int	order[4];
	int	dx;
	int	dy;

	(void)i;
	if (game->nmb_ghost[2] == 0)
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
	dx = game->player_x - game->pinky_x;
	dy = game->player_y - game->pinky_y;
	if (rand() % 4 == 0)
		ft_ghost_patrol(game->max_x, game->max_y, &dx, &dy);
	ft_ghost_priority(dx, dy, order);
	if (ft_moves_pinky2(game, order, 0) == 0)
	{
		game->image.pinky[0]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[0]->instances->y = game->pinky_x * SIZE;
	}
}