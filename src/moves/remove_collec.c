/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_collec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:01:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 19:43:37 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	disable_collec(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->max_collec)
	{
		if (game->image.collec->instances[i].x / SIZE == game->player_y
			&& game->image.collec->instances[i].y / SIZE == game->player_x)
		{
			game->image.collec->instances[i].enabled = 0;
			game->image.fground->instances[i].enabled = 1;
		}
	}
}
