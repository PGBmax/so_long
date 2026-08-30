/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:31:58 by pboucher          #+#    #+#             */
/*   Updated: 2026/08/30 18:31:59 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_opposite(int dir)
{
	if (dir == 0)
		return (1);
	if (dir == 1)
		return (0);
	if (dir == 2)
		return (3);
	return (2);
}

void	ft_ghost_priority(int dx, int dy, int *order)
{
	int	xdir;
	int	ydir;

	if (dx < 0)
		xdir = 0;
	else
		xdir = 1;
	if (dy < 0)
		ydir = 2;
	else
		ydir = 3;
	if (ft_abs(dx) < ft_abs(dy))
	{
		order[0] = ydir;
		order[1] = xdir;
	}
	else
	{
		order[0] = xdir;
		order[1] = ydir;
	}
	order[2] = ft_opposite(order[1]);
	order[3] = ft_opposite(order[0]);
}

void	ft_ghost_flee(int *dx, int *dy)
{
	*dx = -(*dx);
	*dy = -(*dy);
}

void	ft_ghost_patrol(int max_x, int max_y, int *dx, int *dy)
{
	*dx = (rand() % (2 * max_x + 1)) - max_x;
	*dy = (rand() % (2 * max_y + 1)) - max_y;
}