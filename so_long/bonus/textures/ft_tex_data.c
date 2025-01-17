/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:11:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 16:47:21 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	ft_textures_data(t_textures *tex, t_game *game)
{
	tex->digit[0] = ft_load_png("./texb/zero.png", game);
	tex->digit[1] = ft_load_png("./texb/one.png", game);
	tex->digit[2] = ft_load_png("./texb/two.png", game);
	tex->digit[3] = ft_load_png("./texb/three.png", game);
	tex->digit[4] = ft_load_png("./texb/four.png", game);
	tex->digit[5] = ft_load_png("./texb/five.png", game);
	tex->digit[6] = ft_load_png("./texb/six.png", game);
	tex->digit[7] = ft_load_png("./texb/seven.png", game);
	tex->digit[8] = ft_load_png("./texb/eight.png", game);
	tex->digit[9] = ft_load_png("./texb/nine.png", game);
	tex->collec[0] = ft_load_png("./text/collec.png", game);
	tex->collec[1] = ft_load_png("./texb/collec_2.png", game);
	tex->collec[2] = ft_load_png("./texb/collec_3.png", game);
	tex->collec[3] = ft_load_png("./texb/collec_4.png", game);
	tex->ground = ft_load_png("./text/ground.png", game);
	tex->fground = ft_load_png("./text/fake_ground.png", game);
	tex->exit = ft_load_png("./text/exit.png", game);
}
