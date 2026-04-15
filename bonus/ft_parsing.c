/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:28:48 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:45:22 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	ft_check_values(char c)
{
	if (c != '0' && c != '1'
		&& c != 'P' && c != 'E'
		&& c != 'C' && c != 'K'
		&& c != 'O' && c != 'R' && c != 'B')
		return (0);
	return (1);
}

static int	ft_somes_verifs(t_game game, char **map)
{
	if (!map)
		return (0);
	if (game.nmb_player != 1)
		return (ft_error(10));
	if (game.nmb_exit != 1)
		return (ft_error(5));
	if (game.nmb_ghost[0] > 1)
		return (ft_error(13));
	if (game.nmb_ghost[1] > 1)
		return (ft_error(14));
	if (game.nmb_ghost[2] > 1)
		return (ft_error(15));
	if (game.nmb_ghost[3] > 1)
		return (ft_error(16));
	return (1);
}

static int	check_fill(char c)
{
	if (c == 'E')
		return (ft_error(7));
	if (c == 'C')
		return (ft_error(6));
	return (1);
}

int	ft_parsing(t_game game)
{
	int		x;
	int		y;
	char	**map;

	if (game.max_collec == 0)
		return (ft_error(8));
	if (!ft_somes_verifs(game, game.map))
		return (0);
	map = fill_map(game);
	fill(&game, game.player_y, game.player_x, map);
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (!check_fill(map[x][y]))
			{
				free_map(map);
				return (0);
			}
		}
	}
	free_map(map);
	return (1);
}
