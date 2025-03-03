/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:54:35 by hakader           #+#    #+#             */
/*   Updated: 2025/03/03 00:40:10 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fl_walls(t_map *game, int y)
{
	int	x;

	x = 0;
	if (!game->map[y])
		return ;
	while (game->map[y][x] && game->map[y][x] != '\n')
	{
		if (game->map[y][x] != '1')
			put_err("Error:\nCheck your walls\n");
		x++;
	}
	game->column = x;
}

void	check_fl_walls(t_map *game)
{
	int	y;

	y = 0;
	fl_walls(game, 0);
	while (game->map[y + 1])
		y++;
	fl_walls (game, y);
}

void	check_rl_walls(t_map *game)
{
	int (y), (x);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		if (game->map[y][0] != '1' || game->map[y][x - 2] != '1')
			put_err("Error:\nCheck your walls\n");
		y++;
	}
	game->row = y;
}
