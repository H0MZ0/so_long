/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:48 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 01:39:21 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floid_recursive(char **tab, t_axis size, t_axis begin, char target)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y
		|| tab[begin.y][begin.x] != target || tab[begin.y][begin.x] == 'V')
	{
		return ;
	}
	tab[begin.y][begin.x] = 'V';
	floid_recursive(tab, size, (t_axis){begin.x + 1, begin.y}, target);
	floid_recursive(tab, size, (t_axis){begin.x - 1, begin.y}, target);
	floid_recursive(tab, size, (t_axis){begin.x, begin.y + 1}, target);
	floid_recursive(tab, size, (t_axis){begin.x, begin.y - 1}, target);
}

void	flood_fill(t_mlx *mlx)
{
	t_axis	size;
	t_axis	begin;
	char	target;

	size.x = mlx->game.column;
	size.y = mlx->game.row;
	begin.x = mlx->p_x;
	begin.y = mlx->p_y;
	target = mlx->game.copy[begin.y][begin.x];
	if (target == '1' || target == 'V')
	{
		return ;
	}
	floid_recursive(mlx->game.copy, size, begin, target);
}

int	ft_flood_fill_check(t_mlx *mlx)
{
	int		y;
	int		x;
	t_axis	size;

	size.x = mlx->game.column;
	size.y = mlx->game.row;
	flood_fill(mlx);
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (mlx->game.map[y][x] == 'C' || mlx->game.map[y][x] == 'E')
			{
				if (mlx->game.copy[y][x] != 'V')
					return (free_arr(mlx->game.copy), 0);
			}
			x++;
		}
		y++;
	}
	return (free_arr(mlx->game.copy), 1);
}
