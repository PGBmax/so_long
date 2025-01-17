/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_ghost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:54:44 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	ft_textures_ghost2(t_textures *tex, t_game *game)
{
	tex->blinky[4] = ft_load_png("./texb/red_frame0.png", game);
	tex->blinky[5] = ft_load_png("./texb/red_frame1.png", game);
	tex->pinky[4] = ft_load_png("./texb/pink_frame0.png", game);
	tex->pinky[5] = ft_load_png("./texb/pink_frame1.png", game);
	tex->inky[4] = ft_load_png("./texb/cyan_frame0.png", game);
	tex->inky[5] = ft_load_png("./texb/cyan_frame1.png", game);
	tex->clyde[4] = ft_load_png("./texb/orange_frame0.png", game);
	tex->clyde[5] = ft_load_png("./texb/orange_frame1.png", game);
	tex->blinky[6] = ft_load_png("./texb/red_frame2.png", game);
	tex->pinky[6] = ft_load_png("./texb/pink_frame2.png", game);
	tex->inky[6] = ft_load_png("./texb/cyan_frame2.png", game);
	tex->clyde[6] = ft_load_png("./texb/orange_frame2.png", game);
}

void	ft_textures_ghost(t_textures *tex, t_game *game)
{
	tex->inky[0] = ft_load_png("./texb/cyan_up.png", game);
	tex->inky[1] = ft_load_png("./texb/cyan_down.png", game);
	tex->inky[2] = ft_load_png("./texb/cyan_left.png", game);
	tex->inky[3] = ft_load_png("./texb/cyan_right.png", game);
	tex->pinky[0] = ft_load_png("./texb/pink_up.png", game);
	tex->pinky[1] = ft_load_png("./texb/pink_down.png", game);
	tex->pinky[2] = ft_load_png("./texb/pink_left.png", game);
	tex->pinky[3] = ft_load_png("./texb/pink_right.png", game);
	tex->blinky[0] = ft_load_png("./texb/red_up.png", game);
	tex->blinky[1] = ft_load_png("./texb/red_down.png", game);
	tex->blinky[2] = ft_load_png("./texb/red_left.png", game);
	tex->blinky[3] = ft_load_png("./texb/red_right.png", game);
	tex->clyde[0] = ft_load_png("./texb/orange_up.png", game);
	tex->clyde[1] = ft_load_png("./texb/orange_down.png", game);
	tex->clyde[2] = ft_load_png("./texb/orange_left.png", game);
	tex->clyde[3] = ft_load_png("./texb/orange_right.png", game);
}
