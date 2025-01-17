/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:40 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:29:03 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

mlx_texture_t	*ft_load_png(const char *path, t_game *game)
{
	mlx_texture_t	*temp;
	int				check;

	temp = NULL;
	check = open(path, O_RDONLY);
	if (check == -1)
		return (NULL);
	close(check);
	temp = mlx_load_png(path);
	if (temp)
		game->nmb_tex++;
	return (temp);
}

void	ft_delete_texture(mlx_texture_t *tex)
{
	if (tex)
		mlx_delete_texture(tex);
}

static void	ft_create_image2(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		img->pac_man_exit[i] = mlx_texture_to_image(mlx, tex->pac_man_exit[i]);
		img->player[i] = mlx_texture_to_image(mlx, tex->player[i]);
	}
	i = -1;
	while (++i < 7)
	{
		img->clyde[i] = mlx_texture_to_image(mlx, tex->clyde[i]);
		img->inky[i] = mlx_texture_to_image(mlx, tex->inky[i]);
		img->pinky[i] = mlx_texture_to_image(mlx, tex->pinky[i]);
		img->blinky[i] = mlx_texture_to_image(mlx, tex->blinky[i]);
		img->pac_death[i] = mlx_texture_to_image(mlx, tex->pac_death[i]);
	}
	i = -1;
	while (++i < 10)
		img->digit[i] = mlx_texture_to_image(mlx, tex->digit[i]);
	i = -1;
	while (++i < 12)
		img->pac_frame[i] = mlx_texture_to_image(mlx, tex->pac_frame[i]);
}

static void	ft_create_image(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	img->ground = mlx_texture_to_image(mlx, tex->ground);
	img->fground = mlx_texture_to_image(mlx, tex->fground);
	img->exit = mlx_texture_to_image(mlx, tex->exit);
	i = -1;
	while (++i < 3)
		img->walls[i] = mlx_texture_to_image(mlx, tex->walls[i]);
	i = -1;
	while (++i < 4)
	{
		img->clyde[i] = mlx_texture_to_image(mlx, tex->clyde[i]);
		img->inky[i] = mlx_texture_to_image(mlx, tex->inky[i]);
		img->pinky[i] = mlx_texture_to_image(mlx, tex->pinky[i]);
		img->blinky[i] = mlx_texture_to_image(mlx, tex->blinky[i]);
		img->link[i] = mlx_texture_to_image(mlx, tex->link[i]);
		img->off_wall[i] = mlx_texture_to_image(mlx, tex->off_wall[i]);
		img->off_corner[i] = mlx_texture_to_image(mlx, tex->off_corner[i]);
		img->corner[i] = mlx_texture_to_image(mlx, tex->corner[i]);
		img->collec[i] = mlx_texture_to_image(mlx, tex->collec[i]);
	}
}

int	ft_load_t(mlx_t *mlx, t_textures *tex, t_image *img, t_game *g)
{
	ft_textures_ghost(tex, g);
	ft_textures_ghost2(tex, g);
	ft_textures_walls(tex, g);
	ft_textures_data(tex, g);
	ft_textures_player(tex, g);
	if (g->nmb_tex != 93)
		return (ft_error(17));
	ft_create_image(mlx, tex, img);
	ft_create_image2(mlx, tex, img);
	return (1);
}
