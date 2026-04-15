/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:05:31 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 14:33:23 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_textures_walls(t_textures *tex, t_game *game)
{
	tex->off_wall[0] = ft_load_png("./text/walls_left.png", game);
	tex->off_wall[1] = ft_load_png("./text/walls_right.png", game);
	tex->off_wall[2] = ft_load_png("./text/walls_top.png", game);
	tex->off_wall[3] = ft_load_png("./text/walls_bottom.png", game);
	tex->off_corner[0] = ft_load_png("./text/corner_bottom_left.png", game);
	tex->off_corner[1] = ft_load_png("./text/corner_bottom_right.png", game);
	tex->off_corner[2] = ft_load_png("./text/corner_top_left.png", game);
	tex->off_corner[3] = ft_load_png("./text/corner_top_right.png", game);
	tex->corner[0] = ft_load_png("./text/corner_1.png", game);
	tex->corner[1] = ft_load_png("./text/corner_2.png", game);
	tex->corner[2] = ft_load_png("./text/corner_3.png", game);
	tex->corner[3] = ft_load_png("./text/corner_4.png", game);
	tex->link[0] = ft_load_png("./text/link_walls_left.png", game);
	tex->link[1] = ft_load_png("./text/link_walls_right.png", game);
	tex->link[2] = ft_load_png("./text/link_walls_top.png", game);
	tex->link[3] = ft_load_png("./text/link_walls_bottom.png", game);
	tex->walls[0] = ft_load_png("./text/wall_h.png", game);
	tex->walls[1] = ft_load_png("./text/wall_v.png", game);
	tex->walls[2] = ft_load_png("./text/single_wall.png", game);
	tex->pac_man_exit[0] = ft_load_png("./text/pac_man_exit1.png", game);
	tex->pac_man_exit[1] = ft_load_png("./text/pac_man_exit2.png", game);
	tex->pac_man_exit[2] = ft_load_png("./text/pac_man_exit3.png", game);
	tex->pac_man_exit[3] = ft_load_png("./text/pac_man_exit4.png", game);
	tex->pac_man_exit[4] = ft_load_png("./text/pac_man_exit5.png", game);
}
