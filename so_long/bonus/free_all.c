/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:04:03 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:40:13 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	free_textures2(t_textures *tex)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		ft_delete_texture(tex->clyde[i]);
		ft_delete_texture(tex->blinky[i]);
		ft_delete_texture(tex->pinky[i]);
		ft_delete_texture(tex->inky[i]);
		ft_delete_texture(tex->pac_death[i]);
	}
	i = -1;
	while (++i < 10)
		ft_delete_texture(tex->digit[i]);
	i = -1;
	while (++i < 12)
		ft_delete_texture(tex->pac_frame[i]);
}

static void	free_textures(t_textures *tex)
{
	int	i;

	i = -1;
	ft_delete_texture(tex->ground);
	ft_delete_texture(tex->fground);
	ft_delete_texture(tex->exit);
	ft_delete_texture(tex->walls[0]);
	ft_delete_texture(tex->walls[1]);
	ft_delete_texture(tex->walls[2]);
	while (++i < 4)
	{
		ft_delete_texture(tex->off_wall[i]);
		ft_delete_texture(tex->off_corner[i]);
		ft_delete_texture(tex->corner[i]);
		ft_delete_texture(tex->link[i]);
		ft_delete_texture(tex->collec[i]);
	}
	i = -1;
	while (++i < 5)
	{
		ft_delete_texture(tex->player[i]);
		ft_delete_texture(tex->pac_man_exit[i]);
	}
	free_textures2(tex);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map[i]);
	free(map);
}

int	free_all(t_game *game)
{
	free_textures(&game->textures);
	free_map(game->map);
	mlx_terminate(game->mlx);
	return (0);
}
