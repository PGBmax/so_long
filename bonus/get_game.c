/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:14:02 by pboucher          #+#    #+#             */
/*   Updated: 2026/04/13 15:14:37 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_game	*tgame(t_game *info)
{
	static t_game	*data = NULL;

	if (info)
		data = info;
	return (data);
}

void	set_tgame(t_game *info)
{
	tgame(info);
}

t_game	*get_tgame(void)
{
	return (tgame(NULL));
}
