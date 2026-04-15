/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:06:13 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:32 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	ft_pac_man_instances(mlx_image_t *image, t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
		game->image.player[i]->instances->x = -1 * SIZE;
	i = -1;
	while (++i < 12)
		game->image.pac_frame[i]->instances->x = -1 * SIZE;
	image->instances->x = game->player_y * SIZE;
	image->instances->y = game->player_x * SIZE;
}

static void	ft_frame_pac_man_2(t_game *game, int n)
{
	if (game->state == 1 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[2], game);
	if (game->state == 2 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[5], game);
	if (game->state == 3 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[8], game);
	if (game->state == 4 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[11], game);
}

static void	ft_frame_pac_man(t_game *game, int n)
{
	if (n == 5)
		ft_pac_man_instances(game->image.player[0], game);
	if (n == 1)
		ft_pac_man_instances(game->image.player[game->state], game);
	if (game->state == 1 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[0], game);
	if (game->state == 2 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[3], game);
	if (game->state == 3 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[6], game);
	if (game->state == 4 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[9], game);
	if (game->state == 1 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[1], game);
	if (game->state == 2 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[4], game);
	if (game->state == 3 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[7], game);
	if (game->state == 4 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[10], game);
	ft_frame_pac_man_2(game, n);
}

static void	frames_player_2(t_game *game, int *count)
{
	if (*count < FRAMEP * 6)
		ft_frame_pac_man(game, 4);
	else if (*count < FRAMEP * 7)
		ft_frame_pac_man(game, 3);
	else if (*count < FRAMEP * 8)
		ft_frame_pac_man(game, 2);
	else if (*count == FRAMEP * 8)
	{
		ft_frame_pac_man(game, 1);
		*count = 0;
	}
}

void	frames_player(t_game *game)
{
	static int	count = 0;

	if (game->victory != 0)
		return ;
	if (count < FRAMEP * 1)
		ft_frame_pac_man(game, 1);
	else if (count < FRAMEP * 2)
		ft_frame_pac_man(game, 2);
	else if (count < FRAMEP * 3)
		ft_frame_pac_man(game, 3);
	else if (count < FRAMEP * 4)
		ft_frame_pac_man(game, 4);
	else if (count < FRAMEP * 5)
		ft_frame_pac_man(game, 5);
	else
		frames_player_2(game, &count);
	count++;
}
