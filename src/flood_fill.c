/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:36:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 15:46:24 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_know_map(int fd)
{
	char	*map;
	int		i;

	i = 0;
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	return (i);
}

void	fill(t_game *game, int row, int col, char **map)
{
	if (row < 0 || col < 0 || row > game->max_x || col > game->max_y)
		return ;
	if (map[col][row] == '1' || map[col][row] == 'D')
		return ;
	map[col][row] = 'D';
	fill(game, row - 1, col, map);
	fill(game, row + 1, col, map);
	fill(game, row, col + 1, map);
	fill(game, row, col - 1, map);
}

char	**fill_map(t_game game)
{
	char	**map;
	int		x;
	int		y;

	x = -1;
	map = ft_calloc(sizeof(char *), game.max_y + 2);
	map[game.max_y + 1] = NULL;
	while (++x <= game.max_y)
	{
		map[x] = ft_calloc(game.max_x + 2, 1);
		if (!map[x])
			return (NULL);
		y = -1;
		while (++y <= game.max_x)
		{
			map[x][y] = game.map[x][y];
			if (!ft_check_values(map[x][y]))
			{
				ft_error(11);
				return (NULL);
			}
		}
		map[x][y] = 0;
	}
	return (map);
}
