/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:19:00 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:57 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	ft_textures_player(t_textures *tex, t_game *game)
{
	tex->player[0] = ft_load_png("./text/pac_man.png", game);
	tex->player[1] = ft_load_png("./text/pac_up.png", game);
	tex->player[2] = ft_load_png("./text/pac_down.png", game);
	tex->player[3] = ft_load_png("./text/pac_left.png", game);
	tex->player[4] = ft_load_png("./text/pac_right.png", game);
	tex->pac_frame[0] = ft_load_png("./texb/pac_up_2.png", game);
	tex->pac_frame[1] = ft_load_png("./texb/pac_up_3.png", game);
	tex->pac_frame[2] = ft_load_png("./texb/pac_up_4.png", game);
	tex->pac_frame[3] = ft_load_png("./texb/pac_down_2.png", game);
	tex->pac_frame[4] = ft_load_png("./texb/pac_down_3.png", game);
	tex->pac_frame[5] = ft_load_png("./texb/pac_down_4.png", game);
	tex->pac_frame[6] = ft_load_png("./texb/pac_left_2.png", game);
	tex->pac_frame[7] = ft_load_png("./texb/pac_left_3.png", game);
	tex->pac_frame[8] = ft_load_png("./texb/pac_left_4.png", game);
	tex->pac_frame[9] = ft_load_png("./texb/pac_right_2.png", game);
	tex->pac_frame[10] = ft_load_png("./texb/pac_right_3.png", game);
	tex->pac_frame[11] = ft_load_png("./texb/pac_right_4.png", game);
	tex->pac_death[0] = ft_load_png("./texb/pac_death_1.png", game);
	tex->pac_death[1] = ft_load_png("./texb/pac_death_2.png", game);
	tex->pac_death[2] = ft_load_png("./texb/pac_death_3.png", game);
	tex->pac_death[3] = ft_load_png("./texb/pac_death_4.png", game);
	tex->pac_death[4] = ft_load_png("./texb/pac_death_5.png", game);
	tex->pac_death[5] = ft_load_png("./texb/pac_death_6.png", game);
	tex->pac_death[6] = ft_load_png("./texb/pac_death_7.png", game);
}
