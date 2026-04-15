/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:19:00 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:48:46 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_textures_player(t_textures *tex, t_game *game)
{
	tex->player[0] = ft_load_png("./text/pac_man.png", game);
	tex->player[1] = ft_load_png("./text/pac_up.png", game);
	tex->player[2] = ft_load_png("./text/pac_down.png", game);
	tex->player[3] = ft_load_png("./text/pac_left.png", game);
	tex->player[4] = ft_load_png("./text/pac_right.png", game);
}
