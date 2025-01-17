/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:20:43 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	reveal_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->image.exit, x * SIZE, y * SIZE);
}

static int	init_game_values(t_game *game, char *s)
{
	game->moves = 0;
	game->get_collec = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->nmb_exit = 0;
	game->nmb_player = 0;
	game->victory = 0;
	game->state = 0;
	game->nmb_count = 0;
	game->nmb_tex = 0;
	game->error = 0;
	ft_read_map(game, s);
	ft_know_size_map(game);
	if (game->error)
		return (ft_error(11));
	return (1);
}

int	main(int ac, char **av)
{
	t_game			game;

	if (!ft_args_error(ac, av))
		return (0);
	if (!init_game_values(&game, av[1]))
	{
		free_map(game.map);
		return (0);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(game.y * SIZE, game.x * SIZE, "Pac Man", true);
	if (!game.mlx)
	{
		free_map(game.map);
		return (ft_error(12));
	}
	if (!ft_load_t(game.mlx, &game.textures, &game.image, &game))
		return (free_all(&game));
	game.nmb_count = ft_create_map(game.mlx, &game);
	if (!game.nmb_count || !ft_parsing(game))
		return (free_all(&game));
	mlx_key_hook(game.mlx, (void (*))ft_hook, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))ft_screen_victory, (void *)&game);
	mlx_loop(game.mlx);
	free_all(&game);
}
