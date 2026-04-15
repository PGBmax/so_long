/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:40 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:30:01 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

static void	ft_create_image(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	img->ground = mlx_texture_to_image(mlx, tex->ground);
	img->fground = mlx_texture_to_image(mlx, tex->fground);
	img->exit = mlx_texture_to_image(mlx, tex->exit);
	img->collec = mlx_texture_to_image(mlx, tex->collec);
	i = -1;
	while (++i < 3)
		img->walls[i] = mlx_texture_to_image(mlx, tex->walls[i]);
	i = -1;
	while (++i < 4)
	{
		img->link[i] = mlx_texture_to_image(mlx, tex->link[i]);
		img->off_wall[i] = mlx_texture_to_image(mlx, tex->off_wall[i]);
		img->off_corner[i] = mlx_texture_to_image(mlx, tex->off_corner[i]);
		img->corner[i] = mlx_texture_to_image(mlx, tex->corner[i]);
	}
	i = -1;
	while (++i < 5)
	{
		img->pac_man_exit[i] = mlx_texture_to_image(mlx, tex->pac_man_exit[i]);
		img->player[i] = mlx_texture_to_image(mlx, tex->player[i]);
	}
}

int	ft_load_t(mlx_t *mlx, t_textures *tex, t_image *img, t_game *g)
{
	ft_textures_walls(tex, g);
	ft_textures_data(tex, g);
	ft_textures_player(tex, g);
	if (g->nmb_tex != 33)
		return (ft_error(13));
	ft_create_image(mlx, tex, img);
	return (1);
}
