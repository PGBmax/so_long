/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:28:14 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:41:05 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_check_case2(t_game *game, char c)
{
	if (c == 'O')
	{
		game->nmb_ghost[1]++;
		game->clyde_x = game->x;
		game->clyde_y = game->y;
	}
	else if (c == 'K')
	{
		game->nmb_ghost[2]++;
		game->pinky_x = game->x;
		game->pinky_y = game->y;
	}
	else if (c == 'B')
	{
		game->nmb_ghost[3]++;
		game->inky_x = game->x;
		game->inky_y = game->y;
	}
	else
	{
		if ((c != 0 && c != '\n') || (game->map[game->x][0] == 0)
			|| ((game->map[game->x][ft_strlen(game->map[game->x]) - 1] != '\n')
			&& (game->map[game->x][ft_strlen(game->map[game->x]) - 1] != 0)))
			game->error = 1;
	}
}

static void	ft_check_case(t_game *game, char c)
{
	if (c == 'C')
		game->max_collec++;
	else if (c == '1' || c == '0')
		return ;
	else if (c == 'E')
	{
		game->nmb_exit++;
		game->exit_x = game->x;
		game->exit_y = game->y;
	}
	else if (c == 'P')
	{
		game->nmb_player++;
		game->player_x = game->x;
		game->player_y = game->y;
	}
	else if (c == 'R')
	{
		game->nmb_ghost[0]++;
		game->blinky_x = game->x;
		game->blinky_y = game->y;
	}
	else
		ft_check_case2(game, c);
}

void	ft_know_size_map(t_game *game)
{
	game->max_collec = 0;
	game->x = -1;
	while (game->map[++game->x])
	{
		game->y = -1;
		while (game->map[game->x][++game->y])
		{
			ft_check_case(game, game->map[game->x][game->y]);
			if (game->map[game->x][0] == 0)
			{
				free(game->map[game->x]);
				game->x--;
				break ;
			}
		}
	}
	game->max_x = game->y - 1;
	game->max_y = game->x - 1;
}

int	check_map(char *map)
{
	int		i;
	int		j;
	char	*check;

	i = ft_strlen(map) - 1;
	check = ".ber";
	j = ft_strlen(check) - 1;
	while (map[i] == check[j])
	{
		i--;
		j--;
	}
	if (j < 0)
		return (1);
	else
		return (0);
}

int	ft_pars_walls(t_game game)
{
	int	x;
	int	y;

	x = 0;
	while (game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] != '1' && (x == 0 || x == game.max_y))
				return (1);
			if (game.map[x][y] != '1' && (y == 0 || y == game.max_x))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
