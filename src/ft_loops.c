/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:01:59 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:50:27 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	ft_display_victory(t_game *game, mlx_image_t *img, int x)
{
	mlx_image_to_window(game->mlx, img, game->exit_y * SIZE, x * SIZE);
}

void	ft_screen_victory(t_game *game)
{
	static int	count = 0;
	static int	i = 1;

	if (game->victory != 1)
		return ;
	if (count == 0)
		ft_display_victory(game, game->image.player[0], game->exit_x);
	else if (count == 5 * i && i < 6)
	{
		ft_display_victory(game, game->image.pac_man_exit[i - 1], game->exit_x);
		i++;
	}
	else if (count == 5 * 6)
		ft_display_victory(game, game->image.exit, game->exit_x);
	else if (count == 5 * 7)
	{
		mlx_close_window(game->mlx);
		ft_printf("\n\e[92mGood Job! 🎉\n");
		ft_printf("You won with %d moves! 🥳\n\n\e[97m", game->moves);
	}
	count++;
}
