/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:32:05 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:23:25 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	ft_close_game(t_game *game)
{
	mlx_close_window(game->mlx);
	if (game->victory == 1)
	{
		ft_printf("\n\e[93mPac Man");
		ft_printf(" just gave up about winning. 💀\n\n\e[97m");
	}
	else
	{
		ft_printf("\n\e[91mPac Man");
		ft_printf(" just got deleted from the existence. 😔\n\n\e[97m");
	}
}

static void	ft_pac_move(t_game *game, int state)
{
	int	i;

	i = -1;
	while (++i < 5)
		game->image.player[i]->instances->x = -1 * SIZE;
	game->image.player[state]->instances->x = game->player_y * SIZE;
	game->image.player[state]->instances->y = game->player_x * SIZE;
}

static void	ft_move_pac_man(t_game *game, int o, char c, int state)
{
	if (c == 'u' || c == 'd')
		game->player_x = game->player_x + o;
	else
		game->player_y = game->player_y + o;
	ft_pac_move(game, state);
	game->state = state;
	if (o != 0)
	{
		game->moves++;
		ft_printf("\e[96mNumber of steps : %d\n\e[97m", game->moves);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		disable_collec(game);
		game->map[game->player_x][game->player_y] = '0';
		game->get_collec++;
		if (game->get_collec == game->max_collec)
			reveal_exit(game, game->exit_y, game->exit_x);
	}
	if (game->map[game->player_x][game->player_y] == 'E'
		&& game->get_collec == game->max_collec)
		game->victory = 1;
}

static void	ft_hook2(mlx_key_data_t key_data, t_game *game)
{
	if ((key_data.key == UP1 || key_data.key == UP2)
		&& game->map[game->player_x - 1][game->player_y] == '1')
		ft_move_pac_man(game, 0, 'u', 1);
	else if ((key_data.key == DOWN1 || key_data.key == DOWN2)
		&& game->map[game->player_x + 1][game->player_y] == '1')
		ft_move_pac_man(game, 0, 'd', 2);
	else if ((key_data.key == LEFT1 || key_data.key == LEFT2)
		&& game->map[game->player_x][game->player_y - 1] == '1')
		ft_move_pac_man(game, 0, 'l', 3);
	else if ((key_data.key == RIGHT1 || key_data.key == RIGHT2)
		&& game->map[game->player_x][game->player_y + 1] == '1')
		ft_move_pac_man(game, 0, 'r', 4);
}

void	ft_hook(mlx_key_data_t key_data, t_game *game)
{
	if ((key_data.action != MLX_PRESS || game->victory != 0)
		&& key_data.key != MLX_KEY_ESCAPE)
		return ;
	else if (key_data.key == MLX_KEY_ESCAPE)
		ft_close_game(game);
	else if ((key_data.key == UP1 || key_data.key == UP2)
		&& game->map[game->player_x - 1][game->player_y] != '1')
		ft_move_pac_man(game, -1, 'u', 1);
	else if ((key_data.key == DOWN1 || key_data.key == DOWN2)
		&& game->map[game->player_x + 1][game->player_y] != '1')
		ft_move_pac_man(game, 1, 'd', 2);
	else if ((key_data.key == LEFT1 || key_data.key == LEFT2)
		&& game->map[game->player_x][game->player_y - 1] != '1')
		ft_move_pac_man(game, -1, 'l', 3);
	else if ((key_data.key == RIGHT1 || key_data.key == RIGHT2)
		&& game->map[game->player_x][game->player_y + 1] != '1')
		ft_move_pac_man(game, 1, 'r', 4);
	else
		ft_hook2(key_data, game);
}
