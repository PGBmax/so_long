/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:03:38 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/21 15:29:28 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	ft_error2(int n)
{
	if (n == 11)
		ft_printf("A character is not recognized !\n\n\e[97m");
	if (n == 12)
		ft_printf("MLX could not be created!\n\n\e[97m");
	if (n == 13)
		ft_printf("Only one Blinky can exist!\n\n\e[97m");
	if (n == 14)
		ft_printf("Only one Clyde can exist!\n\n\e[97m");
	if (n == 15)
		ft_printf("Only one Pinky can exist!\n\n\e[97m");
	if (n == 16)
		ft_printf("Only one Inky can exist!\n\n\e[97m");
	if (n == 17)
		ft_printf("At least 1 texture is missing!\n\n\e[97m");
	return (0);
}

int	ft_error(int n)
{
	ft_printf("\n\e[91mError!\n");
	if (n == 1)
		ft_printf("Correct Usage : ./so_long <map.ber>\n\n\e[97m");
	if (n == 2)
		ft_printf("Wrong name for map! Must be a .ber\n\n\e[97m");
	if (n == 3)
		ft_printf("This file doesn't exist.\n\n\e[97m");
	if (n == 4)
		ft_printf("Sides of the map must be walls!\n\n\e[97m");
	if (n == 5)
		ft_printf("Only one exit required!\n\n\e[97m");
	if (n == 6)
		ft_printf("At least 1 collectible is inaccessible!\n\n\e[97m");
	if (n == 7)
		ft_printf("The exit is inaccessible!\n\n\e[97m");
	if (n == 8)
		ft_printf("At least 1 collectible is required!\n\n\e[97m");
	if (n == 9)
		ft_printf("The map should be rectangular!\n\n\e[97m");
	if (n == 10)
		ft_printf("Just one player is needed!\n\n\e[97m");
	else
		ft_error2(n);
	return (0);
}

int	ft_args_error(int ac, char **av)
{
	if (ac != 2)
		return (ft_error(1));
	if (!check_map(av[1]))
		return (ft_error(2));
	if (!open(av[1], O_RDONLY) || open(av[1], O_RDONLY) == -1)
		return (ft_error(3));
	return (1);
}
